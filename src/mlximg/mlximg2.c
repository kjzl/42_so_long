/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 05:54:17 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:44:38 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlximg.h"

void	mlximg_destroy(void *mlx, t_mlximg *mlximg)
{
	if (mlximg->mlxdata)
		mlx_destroy_image(mlx, mlximg->mlxdata);
	*mlximg = (t_mlximg){0};
}
