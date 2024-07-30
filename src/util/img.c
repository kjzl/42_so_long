/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:10:17 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/23 00:42:53 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	iteri_img_destroy(t_vec *vec, size_t i, void *mlx)
{
	img_destroy(mlx, vec_get_at(vec, i));
}
