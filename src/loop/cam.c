/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:14:43 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/09 17:24:11 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	cam_init(t_gamestate *st)
{
	if (st->opts.cam_mode == CENTER_PLAYER)
		st->cam_offset = rect_center_at(tile_pos_abs(st, st->player.obj.tile),
				st->win_size.width, st->win_size.height).from;
	else if (st->opts.cam_mode == CENTER_MAP)
	{
		st->cam_offset = rect_center_in(rect(st->win_size.width,
					st->win_size.height), st->level.width * st->opts.scale
				* SPRITE_SIZE, st->level.height * st->opts.scale
				* SPRITE_SIZE).from;
		st->cam_offset.x = -st->cam_offset.x;
		st->cam_offset.y = -st->cam_offset.y;
	}
}

void	cam_update(t_gamestate *st)
{
	if (st->opts.cam_mode == CENTER_PLAYER)
		st->cam_offset = rect_center_at(tile_pos_abs(st, st->player.obj.tile),
				st->win_size.width, st->win_size.height).from;
}
