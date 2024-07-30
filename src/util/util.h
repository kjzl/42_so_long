/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:09:25 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 04:59:22 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "../so_long.h"


typedef void	(*tile_iter)(t_upoint pos, t_upoint x_y_max, char tile, void *info);

void			level_iter(const t_level *level, tile_iter iter, void *extra);
t_levelinfo	level_info_empty(void);
void			level_info_destroy(t_levelinfo *info);
t_bool			level_info_clone(const t_levelinfo *info, t_levelinfo *out);
t_bool			vec_strs_into_level(t_vec *vec, t_level *out);
void			level_destroy(t_level *level);
t_bool			level_clone(const t_level *level, t_level *out);
void			level_print(const t_level *level, int fd);
t_bool			is_no_tile_at(const char *c);
t_bool			is_tile_at(const char *c);
t_bool			is_tile(char c);
t_bool			is_no_tile(char c);

t_bool			pos_is_on_edge(t_upoint pos, t_upoint x_y_max);

t_bool			spos_is_neg(t_point var);

void			iteri_img_destroy(t_vec *vec, size_t i, void *mlx);

t_bool			img_init_addr_be(t_img *img, size_t *bits_per_pixel,
					size_t *size_line);

#endif
