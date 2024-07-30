/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:37:49 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/22 18:52:39 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_bool	img_init_addr_be(t_img *img, size_t *bits_per_pixel, size_t *size_line)
{
	int		bpp;
	int		line_len;
	int		big_endian;

	img->pixels = (int *)mlx_get_data_addr(img->mlx_img,
		&bpp, &line_len, &big_endian);
	*bits_per_pixel = bpp;
	*size_line = line_len;
	img->big_endian = (t_bool)big_endian;
	return (img->pixels != 0);
}

// out->mlx_img = mlx_xpm_file_to_image(mlx, path, &out->width, &out->height);

// t_bool	img_init_mlx_xpm

