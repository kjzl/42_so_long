/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 05:54:17 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 06:36:26 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlximg.h"

void	mlximg_destroy(void *mlx, t_mlximg *mlximg)
{
	if (mlximg->mlxdata)
		mlx_destroy_image(mlx, mlximg->mlxdata);
	*mlximg = (t_mlximg){0};
}

void	mlximg_vec_destroy(void *mlx, t_vec *mlximgs)
{
	t_mlximg	*mlximg;
	size_t		i;

	mlximg = vec_get(mlximgs);
	i = 0;
	while (i < mlximgs->len)
		mlximg_destroy(mlx, mlximg + i++);
	vec_destroy(mlximgs, 0);
}

t_bool	mlximg_from_xpm_split(void *mlx, const char *path, t_size size,
			t_vec *out)
{
	t_mlximg	xpm;
	
	return (mlximg_from_xpm(mlx, path, &xpm)
		&& mlximg_split_sprite(mlx, &xpm, size, out));
}
