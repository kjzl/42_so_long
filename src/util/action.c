/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:48:37 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:29:26 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_action	map_inp_to_action(int32_t	input)
{
	static const uint8_t	map[1 << 16] = {
	[INPUT_ARROW_UP] = ACTION_UP,
	[INPUT_ARROW_DOWN] = ACTION_DOWN,
	[INPUT_ARROW_LEFT] = ACTION_LEFT,
	[INPUT_ARROW_RIGHT] = ACTION_RIGHT,
	[INPUT_W] = ACTION_UP,
	[INPUT_S] = ACTION_DOWN,
	[INPUT_A] = ACTION_LEFT,
	[INPUT_D] = ACTION_RIGHT,
	[INPUT_ESCAPE] = ACTION_EXIT,
	[INPUT_Q] = ACTION_EXIT,
	[INPUT_R] = ACTION_RESTART,
	[INPUT_PLUS] = ACTION_ZOOM_IN,
	[INPUT_MINUS] = ACTION_ZOOM_OUT,
	[INPUT_SPACE] = ACTION_CAM_MODE_TOGGLE,
	};

	return (map[input]);
}
