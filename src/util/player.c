/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:24:03 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:25:46 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	update_used_player_sprite(t_gamestate *st, t_action move)
{
	static const t_dir	dir_map[ACTION_COUNT] = {
	[ACTION_UP] = UP, [ACTION_DOWN] = DOWN,
	[ACTION_LEFT] = LEFT, [ACTION_RIGHT] = RIGHT,
	};

	if (upoint_eq(st->player.obj.tile, st->levelinfo.exit))
		st->player.obj.sprite = &st->assets.player_on_exit[dir_map[move]];
	else
		st->player.obj.sprite = &st->assets.player[dir_map[move]];
}
