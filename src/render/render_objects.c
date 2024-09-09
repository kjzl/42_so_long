/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:01:35 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/09 17:23:50 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	object_render(t_gamestate *st, t_object *obj)
{
	t_rect	window;
	t_point	tile_pt;

	window = rect_at(point(st->opts.scale * -SPRITE_SIZE, st->opts.scale * -SPRITE_SIZE), st->win_size.width + 2 * st->opts.scale * SPRITE_SIZE, st->win_size.height + 2 * st->opts.scale * SPRITE_SIZE);
	tile_pt = tile_pos_abs_offset(st, obj->tile);
	if (rect_contains(window, tile_pt))
		mlx_put_image_to_window(st->mlx, st->mlx_win,
			obj->sprite->scaled.mlxdata, tile_pt.x, tile_pt.y);
	// if (point_is_pos(tile_pt) && urect_contains(urect(st->win_size.width,
	// 			st->win_size.height), point_as_upoint(tile_pt)))
}

void	objects_render(t_gamestate *st)
{
	size_t	i;

	i = 0;
	object_render(st, &st->player.obj);
	while (i < st->coins.len)
	{
		object_render(st, vec_get_at(&st->coins, i));
		i++;
	}
}
