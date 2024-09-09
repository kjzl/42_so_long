/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:26:44 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/20 12:28:03 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_bool	is_no_tile_at(const uint8_t *c)
{
	return (!(*c == WALL || *c == FLOOR || *c == COIN || *c == EXIT
			|| *c == START));
}

t_bool	is_tile_at(const uint8_t *c)
{
	return (!is_no_tile_at(c));
}

t_bool	is_tile(uint8_t c)
{
	return (c == WALL || c == FLOOR || c == COIN || c == EXIT || c == START);
}

t_bool	is_no_tile(uint8_t c)
{
	return (!is_tile(c));
}

t_bool	tile_can_be_walked_on(uint8_t c)
{
	return (c == FLOOR || c == COIN || c == EXIT || c == START);
}

// t_object	object_at(t_gamestate *st, t_point tile)
// {

// }
