/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:48:47 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/09 17:23:54 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render(t_gamestate *st)
{
	mlx_clear_window(st->mlx, st->mlx_win);
	level_render(st);
	objects_render(st);
}
