/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:10:00 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/25 16:45:06 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	level_iter(const t_level *level, t_tile_iter iter, void *extra)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < level->height)
	{
		x = 0;
		while (x < level->width)
		{
			iter((t_upoint){x, y}, (t_upoint){level->width - 1, level->height
				- 1}, level->tiles[y][x], extra);
			x++;
		}
		y++;
	}
}

// prints the whole level using ft_putendl_fd
void	level_print(const t_level *level, int fd)
{
	size_t	y;

	y = 0;
	while (y < level->height)
	{
		ft_putendl_fd(level->tiles[y], fd);
		y++;
	}
}

/// @brief Convert a vec of t_str into a t_level
/// @param vec A vec<t_str> of strings of equal length
/// @param out The output level
/// @return True if the conversion was successful.
t_bool	vec_strs_into_level(t_vec *vec, t_level *out)
{
	out->height = vec->len;
	out->width = ((t_str *)vec_get(vec))->len;
	if (!vec_strs_into_cstrs(vec))
	{
		vec_destroy(vec, iter_str_destroy);
		return (FALSE);
	}
	out->tiles = vec_take(vec);
	if (out->tiles == 0)
		vec_destroy(vec, iter_ptr_free);
	return (out->tiles != 0);
}

void	level_destroy(t_level *level)
{
	if (level->tiles)
		array_free(level->tiles, level->height, sizeof(char *), iter_ptr_free);
	*level = (t_level){0};
}

t_bool	level_clone(const t_level *level, t_level *out)
{
	t_vec	tmp;

	*out = *level;
	tmp = vec_new_from(level->tiles, sizeof(char *), level->height);
	if (!vec_cstrs_clone(&tmp, &tmp))
		return (FALSE);
	out->tiles = vec_take(&tmp);
	if (out->tiles == 0)
	{
		vec_destroy(&tmp, iter_ptr_free);
		return (FALSE);
	}
	return (TRUE);
}
