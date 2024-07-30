/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg_split_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:21:31 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 06:35:30 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlximg.h"

/// Checks for possible rect with size at given point or first point in next row
static t_bool	next_sprite_part(t_upoint pt, t_size size, t_urect constraint,
			t_urect *out)
{
	*out = urect_constrain(urect_at(pt, size.width, size.height), constraint);
	if (out->size.width != size.width || out->size.height != size.height)
		*out = urect_constrain(urect_at(upoint(0, pt.y + size.height),
					size.width, size.height), constraint);
	return (out->size.width == size.width && out->size.height == size.height);
}

static size_t	sprite_part_count(t_img *img, t_size size)
{
	t_urect	part;
	size_t	i;

	part = urect(0, 0);
	i = 0;
	while (next_sprite_part(part.to, size, img->urect, &part))
		i++;
	return (i);
}

/// @brief Splits an img into parts of size
/// @param mlx mlx pointer
/// @param in input img
/// @param size size of parts
/// @param out output vec
/// @note always destroys `in`
/// @return TRUE on success
t_bool	mlximg_split_sprite(void *mlx, t_mlximg *in, t_size size, t_vec *out)
{
	size_t	parts;
	t_urect	part;

	parts = sprite_part_count(&in->img, size);
	part = urect(0, 0);
	*out = vec_empty_with_capacity(sizeof(t_mlximg), parts);
	if (!out->mem_err)
	{
		while (next_sprite_part(part.to, size, in->img.urect, &part))
		{
			if (!mlximg_clone(mlx, imgview_urect(&in->img, part),
					vec_get_next_uninit_incr_len(out)))
			{
				mlximg_vec_destroy(mlx, out);
				mlximg_destroy(mlx, in);
				return (FALSE);
			}
		}
	}
	mlximg_destroy(mlx, in);
	return (!out->mem_err && parts > 0);
}
