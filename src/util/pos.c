/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:25:00 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 04:59:40 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_bool	pos_is_on_edge(t_upoint pos, t_upoint x_y_max)
{
	return (pos.x == 0 || pos.y == 0 || pos.x == x_y_max.x
		|| pos.y == x_y_max.y);
}

t_point	tile_pos_abs(t_gamestate *st, t_upoint tile)
{
	return (point(tile.x * SPRITE_SIZE * st->opts.scale, tile.y * SPRITE_SIZE
			* st->opts.scale));
}

t_point	tile_pos_abs_offset(t_gamestate *st, t_upoint tile)
{
	return (point_sub(tile_pos_abs(st, tile), st->cam_offset));
}
