/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spos.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:06:39 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 04:59:33 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_bool	spos_is_neg(t_point var)
{
	return (var.x < 0 || var.y < 0);
}
