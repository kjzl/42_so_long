/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:09:25 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/21 00:24:34 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "../so_long.h"


typedef void	(*tile_iter)(t_pos pos, t_pos x_y_max, char tile, void *info);

void			level_iter(const t_level *level, tile_iter iter, void *extra);
t_bool			pos_is_on_edge(t_pos pos, t_pos x_y_max);
t_level_info	level_info_empty(void);
void			level_info_destroy(t_level_info *info);
t_bool			level_info_clone(const t_level_info *info, t_level_info *out);
t_bool			vec_strs_into_level(t_vec *vec, t_level *out);
void			level_destroy(t_level *level);
t_bool			level_clone(const t_level *level, t_level *out);
void			level_print(const t_level *level, int fd);
t_bool			is_no_tile_at(const char *c);
t_bool			is_tile_at(const char *c);
t_bool			is_tile(char c);
t_bool			is_no_tile(char c);

#endif
