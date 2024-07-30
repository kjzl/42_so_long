/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:12:36 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/25 16:40:35 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	display_parse_err(int errs, const t_level *level)
{
	ft_putstr_fd("Error", 2);
	if (errno != 0)
		ft_printf_fd(2, ": %s", strerror(errno));
	ft_putchar_fd('\n', 2);
	if (ERR_LEVEL_NO_RECT & errs)
		ft_putendl_fd("The map must be rectangular (and min 3x5).", 2);
	if (ERR_LEVEL_UNRECOGNIZED_TILE & errs)
		ft_putendl_fd("The map can only be composed of"
			" these 5 characters: \"01CEP\".", 2);
	if (ERR_LEVEL_MULTI_START & errs || ERR_LEVEL_NO_START & errs)
		ft_putendl_fd("The map must contain exactly 1 starting position.", 2);
	if (ERR_LEVEL_MULTI_EXIT & errs || ERR_LEVEL_NO_EXIT & errs)
		ft_putendl_fd("The map must contain exactly 1 exit.", 2);
	if (ERR_LEVEL_NO_WALLS & errs)
		ft_putendl_fd("The map must be surrounded by walls.", 2);
	if (ERR_LEVEL_NO_COINS & errs)
		ft_putendl_fd("The map must contain at least 1 coin.", 2);
	if (ERR_LEVEL_UNREACHABLE_COINS & errs)
		ft_putendl_fd("Some coins are unreachable.", 2);
	if (ERR_LEVEL_UNREACHABLE_EXIT & errs)
		ft_putendl_fd("The exit is unreachable.", 2);
	if (ERR_LEVEL_UNREACHABLE_COINS & errs || ERR_LEVEL_UNREACHABLE_EXIT & errs)
		level_print(level, 2);
}

static t_bool	map_size_valid(size_t width, size_t height)
{
	return (width >= 3 && height >= 3 && width * height >= 3*5);
}

/// @brief This function reads the level from the file descriptor
/// and verifies that it is rectangular.
/// @param fd The file descriptor to read from (will be closed)
/// @param out The output vec<t_str>
/// @return Wheter the level was read successfully
/// (`out` needs to be destroyed either way)
static t_bool	read_tiles_rect(int fd, t_vec *out)
{
	t_str_slice	tmp_line;
	t_str		*tile_row;

	*out = vec_empty_with_capacity(sizeof(t_str), 16);
	while (TRUE)
	{
		tile_row = vec_get_next_uninit(out);
		if (!tile_row)
			break ;
		tmp_line = cstr_view(get_next_line(fd));
		if (!tmp_line.str)
		{
			close(fd);
			return (map_size_valid(out->len, ((t_str *)vec_get(out))->len));
		}
		*tile_row = str_from_parts((char *)tmp_line.str, tmp_line.len);
		out->len++;
		if (strsl_ends_with(tmp_line, cstr_slice("\n", 1)))
			str_pop(tile_row);
		if (((t_str *)vec_get(out))->len != tile_row->len)
			break ;
	}
	close(fd);
	get_next_line_finish(fd);
	return (FALSE);
}

static void	init_parse_map_out(t_level *out, t_levelinfo *out_info)
{
	*out = (t_level){0};
	*out_info = level_info_empty();
}

/// @brief Parses the level from the file descriptor, which will be closed.
/// @param fd The file descriptor to read from
/// @param out The parsed level
/// @return Whether the level was parsed successfully
/// @note If the level was not parsed successfully, the error will be displayed.
t_bool	parse_map(int fd, t_level *out, t_levelinfo *out_info)
{
	t_vec			tmp;

	init_parse_map_out(out, out_info);
	if (!read_tiles_rect(fd, &tmp))
	{
		if (errno == 0)
			display_parse_err(ERR_LEVEL_NO_RECT, 0);
		else
			display_parse_err(0, 0);
		vec_destroy(&tmp, iter_str_destroy);
		return (FALSE);
	}
	if (!vec_strs_into_level(&tmp, out))
	{
		display_parse_err(0, 0);
		return (FALSE);
	}
	if (!validate_level(out, out_info))
	{
		display_parse_err(out_info->errs, out);
		level_destroy(out);
		level_info_destroy(out_info);
		return (FALSE);
	}
	return (TRUE);
}
