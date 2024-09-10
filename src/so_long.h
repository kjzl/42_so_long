/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:33:29 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:51:00 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# pragma once

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define SPRITE_SIZE 16
# define SCALE_MAX 4

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "so_long_types.h"
# include "mlximg/mlximg.h"
# include "util/util.h"
# include "loop/loop.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_bool	parse_map(int fd, t_level *out, t_levelinfo *out_info);

void	win(t_gamestate *st);

void	init_assets(t_gamestate *st);
void	update_scaled_assets(t_gamestate *st);
void	destroy_assets(t_gamestate *st);
void	reset_game(t_gamestate *st);
int32_t	gamestate_destroy(t_gamestate *st);

#endif
