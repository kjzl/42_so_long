/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:21:39 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/09 17:23:46 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	init_coins(t_gamestate *st, t_levelinfo *info)
{
	size_t		i;
	t_upoint	*data;
	t_object	coin;

	i = 0;
	data = vec_get(&info->coins);
	vec_destroy(&st->coins, 0);
	st->coins = vec_empty_with_capacity(sizeof(t_object), info->coins.len);
	while (i < info->coins.len)
	{
		coin = (t_object){.tile = data[i], .sprite = &st->assets.coin};
		vec_push(&st->coins, &coin);
		i++;
	}
}
