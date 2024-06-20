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

t_bool	is_no_tile_at(const char *c)
{
	return (!(*c == WALL || *c == EMPTY || *c == COIN || *c == EXIT
			|| *c == START));
}

t_bool	is_tile_at(const char *c)
{
	return (!is_no_tile_at(c));
}

t_bool	is_tile(char c)
{
	return (c == WALL || c == EMPTY || c == COIN || c == EXIT || c == START);
}

t_bool	is_no_tile(char c)
{
	return (!is_tile(c));
}
