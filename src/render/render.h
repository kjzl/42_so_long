/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:46:11 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/09 17:24:49 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# pragma once

# include "../so_long.h"

void	level_render(t_gamestate *st);
void	objects_render(t_gamestate *st);
void	render(t_gamestate *st);

#endif
