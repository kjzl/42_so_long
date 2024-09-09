/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:22:04 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/09 17:24:12 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static const t_object	*coin_at(t_gamestate *st, t_upoint tile)
{
	size_t			i;
	const t_object	*data;

	i = 0;
	data = vec_get(&st->coins);
	while (i < st->coins.len)
	{
		if (upoint_eq(tile, data[i].tile))
			return (data + i);
		i++;
	}
	return (0);
}

/// handles players walking over coins and exits
void	handle_collisions(t_gamestate *st)
{
	const t_object	*coin;

	if (st->level.tiles[st->player.obj.tile.y][st->player.obj.tile.x] == EXIT
		&& st->coins.len == 0)
	{
		win(st);
		return ;
	}
	coin = coin_at(st, st->player.obj.tile);
	if (coin != 0)
	{
		vec_remove(&st->coins, coin);
		st->player.score++;
	}
}
