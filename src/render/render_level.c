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
	t_rect		window;
	t_upoint	tile;
	t_point		tile_pt;

	window = rect_at(point(st->opts.scale * -SPRITE_SIZE, st->opts.scale * -SPRITE_SIZE), st->win_size.width + 2 * st->opts.scale * SPRITE_SIZE, st->win_size.height + 2 * st->opts.scale * SPRITE_SIZE);
	tile.y = 0;
	while (tile.y < st->level.height)
	{
		tile.x = 0;
		while (tile.x < st->level.width)
		{
			tile_pt = tile_pos_abs_offset(st, tile);
			if (rect_contains(window, tile_pt))
				mlx_put_image_to_window(st->mlx, st->mlx_win, tile_mlxdata(st,
						tile), tile_pt.x, tile_pt.y);
			tile.x++;
		}
		tile.y++;
	}
}
