/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:40:57 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:29:26 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render/render.h"
#include "ft_types.h"
#include "geo/ft_geo.h"
#include "loop.h"

static void	handle_move(t_gamestate *st, t_action action)
{
	t_point					new_pos;
	static const t_point	move_map[ACTION_COUNT] = {
	[ACTION_UP] = {0, -1}, [ACTION_DOWN] = {0, 1},
	[ACTION_LEFT] = {-1, 0}, [ACTION_RIGHT] = {1, 0},
	};

	if (st->status != PREGAME && st->status != PLAYING)
		return ;
	st->status = PLAYING;
	new_pos = point_add(st->player.obj.tile.point, move_map[action]);
	if (tile_can_be_walked_on(st->level.tiles[new_pos.y][new_pos.x]))
	{
		st->player.obj.tile = point_as_upoint(new_pos);
		st->player.moves++;
		ft_printf("Moves: %u\n", st->player.moves);
		cam_update(st);
		handle_collisions(st);
	}
	update_used_player_sprite(st, action);
	render(st);
}

static void	handle_stop(t_gamestate *st, t_action action)
{
	if (action == ACTION_RESTART)
		reset_game(st);
	else
		gamestate_destroy(st);
}

static void	handle_zoom(t_gamestate *st, t_action action)
{
	if (st->opts.scale == 1 && action == ACTION_ZOOM_OUT)
		return ;
	if (st->opts.scale == SCALE_MAX && action == ACTION_ZOOM_IN)
		return ;
	if (action == ACTION_ZOOM_IN)
		st->opts.scale++;
	else
		st->opts.scale--;
	update_scaled_assets(st);
	cam_init(st);
	render(st);
}

static void	handle_cam_mode_toggle(t_gamestate *st, t_action action)
{
	(void)action;
	if (st->opts.cam_mode == CENTER_PLAYER)
		st->opts.cam_mode = CENTER_MAP;
	else
		st->opts.cam_mode = CENTER_PLAYER;
	cam_init(st);
	render(st);
}

void	handle_input(t_gamestate *st, int32_t input)
{
	t_action						action;
	static const t_input_handler	handlers[ACTION_COUNT] = {
	[ACTION_UP] = handle_move,
	[ACTION_DOWN] = handle_move,
	[ACTION_LEFT] = handle_move,
	[ACTION_RIGHT] = handle_move,
	[ACTION_EXIT] = handle_stop,
	[ACTION_RESTART] = handle_stop,
	[ACTION_ZOOM_IN] = handle_zoom,
	[ACTION_ZOOM_OUT] = handle_zoom,
	[ACTION_CAM_MODE_TOGGLE] = handle_cam_mode_toggle,
	};

	action = map_inp_to_action(input);
	if (handlers[action] != 0)
		handlers[action](st, action);
}
