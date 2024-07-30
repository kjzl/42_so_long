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
