/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:58:58 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/21 00:28:12 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO: check for invalid file extension.

int main(int argc, char **argv)
{
	t_level			level;
	t_level_info	info;
	int				fd;

	if (argc != 2 || !strsl_ends_with(cstr_view(argv[1]), cstr_slice(".ber", 4)))
	{
		ft_putendl_fd("Usage: ./so_long <map_file.ber>", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		return (1);
	}
	if (parse_map(fd, &level, &info))
	{
		level_destroy(&level);
		level_info_destroy(&info);
		ft_putendl_fd("Valid ✓", 2);
		return (0);
	}
	else
	{
		level_destroy(&level);
		level_info_destroy(&info);
		return (1);
	}
	// t_vec	map;

	// if (read_tiles_rect(0, &map))
	// {
	// 	ft_putstr_fd("Is Rect and only recognized chars\n", 2);
	// 	ft_printf("map cols: %zu\n", map.len);
	// 	ft_printf("map rows: %zu\n", ((t_str *)vec_get(&map))->len);
	// 	size_t i = 0;
	// 	while (i < map.len)
	// 	{
	// 		ft_printf("%s\n", cstr_ref(vec_get_at(&map, i)));
	// 		i++;
	// 	}
	// 	vec_destroy(&map, iter_str_destroy);
	// 	return (0);
	// }
	// else
	// {
	// 	ft_putstr_fd("Invalid\n", 2);
	// 	vec_destroy(&map, iter_str_destroy);
	// 	return (1);
	// }
}
