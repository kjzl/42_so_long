/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:46:40 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/09 17:23:52 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo/ft_geo.h"
#include "render.h"

static void	*tile_mlxdata(t_gamestate *st, t_upoint tile)
{
	t_sprite	*sprite;

	if (st->level.tiles[tile.y][tile.x] == WALL)
		sprite = &st->assets.wall;
	else if (st->level.tiles[tile.y][tile.x] == EXIT)
		sprite = &st->assets.exit;
	else
		sprite = &st->assets.floor;
	return (sprite->scaled.mlxdata);
}

void	level_render(t_gamestate *st)
{
	t_urect		window;
	t_upoint	tile;
	t_point		tile_pt;

	window = urect(st->win_size.width, st->win_size.height);
	tile.y = 0;
	while (tile.y < st->level.height)
	{
		tile.x = 0;
		while (tile.x < st->level.width)
		{
			tile_pt = tile_pos_abs_offset(st, tile);
			mlx_put_image_to_window(st->mlx, st->mlx_win, tile_mlxdata(st,
					tile), tile_pt.x, tile_pt.y);
			// if (tile_pt.x >= (-SPRITE_SIZE * st->opts.scale) && tile_pt.y >= (-SPRITE_SIZE * st->opts.scale) && urect_contains(window,
			// 		point_as_upoint(tile_pt)))

			tile.x++;
		}
		tile.y++;
	}
}
