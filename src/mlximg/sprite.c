/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:41:18 by kwurster          #+#    #+#             */
/*   Updated: 2024/07/01 00:35:34 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlximg.h"

// t_bool	sprite_from_xpm(void *mlx, const char *path, t_size size,
// 			t_sprite *out)
// {
// 	t_mlximg	xpm;

// 	*out = (t_sprite){0};
// 	if (!mlximg_from_xpm_split(mlx, path, size, &out->imgs))
// 		return (FALSE);
// 	return (TRUE);
// }

// static void	img_rotate_dir(t_img *src, t_img *dest_cp, t_dir dir)
// {
// 	if (dir == LEFT)
// 		imgview_flip_h(imgview(dest_cp));
// 	else if (dir == UP)
// 		imgview_rotate270(imgview(src), imgview(dest_cp));
// 	else if (dir == DOWN)
// 		imgview_rotate90(imgview(src), imgview(dest_cp));
// }

// t_bool	sprite_rotate_dir(void *mlx, t_sprite *src, t_dir dir, t_sprite *out)
// {
// 	t_mlximg	*srcimg;
// 	t_mlximg	*outimg;
// 	size_t		i;

// 	srcimg = vec_get(&src->imgs);
// 	*out = (t_sprite){};
// 	out->imgs = vec_empty_with_capacity(sizeof(t_mlximg), src->imgs.len);
// 	i = 0;
// 	if (out->imgs.mem_err)
// 		return (FALSE);
// 	while (i < src->imgs.len)
// 	{
// 		if (!mlximg_clone(mlx, imgview(&srcimg[i].img), outimg + i))
// 			break;
// 		img_rotate_dir(&srcimg[i].img, &outimg[i].img, dir);
// 		i++;
// 	}
// 	out->imgs.len = i;
// 	if (i != src->imgs.len)
// 		mlximg_vec_destroy(mlx, &out->imgs);
// 	return (i == src->imgs.len);
// }

// t_bool	sprite_rotate_dirs(void *mlx, t_sprite *src, t_sprite out[4])
// {

// }
