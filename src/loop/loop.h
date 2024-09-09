/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:14:38 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/09 17:24:16 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# pragma once

# include "../so_long.h"

typedef void	(*t_input_handler)(t_gamestate *st, t_action action);

void	cam_update(t_gamestate *st);
void	cam_init(t_gamestate *st);
void	handle_input(t_gamestate *st, int32_t input);
void	handle_collisions(t_gamestate *st);
#endif
