/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:23:33 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 06:23:41 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXIMG_H
# define MLXIMG_H
# pragma once

# include "../so_long.h"

void	mlximg_vec_destroy(void *mlx, t_vec *mlximgs);
void	mlximg_destroy(void *mlx, t_mlximg *mlximg);
t_bool	mlximg_empty(void *mlx, uint32_t width, uint32_t height, t_mlximg *out);
t_bool	mlximg_from_xpm(void *mlx, const char *path, t_mlximg *out);
t_bool	mlximg_clone(void *mlx, t_imgview src, t_mlximg *out);
t_bool	mlximg_clone_scaled(void *mlx, t_imgview src, size_t scale,
			t_mlximg *out);

#endif
