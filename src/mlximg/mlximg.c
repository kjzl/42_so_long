/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:23:23 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/09 17:24:08 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlximg.h"

static t_bool	mlx_img_addr_checked(void *mlximg_data,
					uint32_t width, uint32_t **px)
{
	int	bpp;
	int	line_len;
	int	endian;

	*px = (uint32_t *)mlx_get_data_addr(mlximg_data, &bpp, &line_len, &endian);
	if (bpp != 32 || line_len != width * 4 || endian != 0)
	{
		ft_printf_fd(2, "Error: Invalid image format\n");
		return (FALSE);
	}
	return (*px != 0);
}

t_bool	mlximg_empty(void *mlx, uint32_t width, uint32_t height, t_mlximg *out)
{
	out->img = (t_img){0};
	out->mlxdata = mlx_new_image(mlx, width, height);
	if (!out->mlxdata)
		return (FALSE);
	if (!mlx_img_addr_checked(out->mlxdata, width, &out->img.px))
	{
		mlx_destroy_image(mlx, out->mlxdata);
		return (FALSE);
	}
	out->img = img(out->img.px, width, height);
	return (TRUE);
}

t_bool	mlximg_from_xpm(void *mlx, const char *path, t_mlximg *out)
{
	int	width;
	int	height;

	out->img = (t_img){0};
	out->mlxdata = mlx_xpm_file_to_image(mlx, (char *)path, &width, &height);
	if (!out->mlxdata)
	{
		perror(path);
		return (FALSE);
	}
	if (!mlx_img_addr_checked(out->mlxdata, width, &out->img.px))
	{
		mlx_destroy_image(mlx, out->mlxdata);
		return (FALSE);
	}
	out->img = img(out->img.px, width, height);
	return (TRUE);
}

t_bool	mlximg_clone(void *mlx, t_imgview src, t_mlximg *out)
{
	if (!mlximg_empty(mlx, src.width, src.height, out))
		return (FALSE);
	imgview_copy(src, imgview(&out->img));
	return (TRUE);
}

t_bool	mlximg_clone_scaled(void *mlx, t_imgview src, size_t scale,
			t_mlximg *out)
{
	if (!mlximg_empty(mlx, src.width * scale, src.height * scale, out))
		return (FALSE);
	imgview_copy_scaled(src, imgview(&out->img), scale);
	return (TRUE);
}
