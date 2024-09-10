/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:09:25 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:48:23 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# pragma once

# include "../so_long.h"

typedef void	(*t_tile_iter)(t_upoint pos, t_upoint x_y_max, uint8_t tile,
		void *info);

void			level_iter(const t_level *level, t_tile_iter iter, void *extra);
t_levelinfo		level_info_empty(void);
void			level_info_destroy(t_levelinfo *info);
t_bool			level_info_clone(const t_levelinfo *info, t_levelinfo *out);
t_bool			vec_strs_into_level(t_vec *vec, t_level *out);
void			level_destroy(t_level *level);
t_bool			level_clone(const t_level *level, t_level *out);
void			level_print(const t_level *level, int fd);
t_bool			tile_can_be_walked_on(uint8_t c);
t_bool			pos_is_on_edge(t_upoint pos, t_upoint x_y_max);
t_point			tile_pos_abs(t_gamestate *st, t_upoint tile);
t_point			tile_pos_abs_offset(t_gamestate *st, t_upoint tile);
t_action		map_inp_to_action(int32_t input);
void			init_coins(t_gamestate *st, t_levelinfo *info);
void			load_asset_with_bg(t_gamestate *st, t_mlximg *bg,
					const char *path, t_mlximg *out);
void			blend_asset_with_bg(t_gamestate *st, t_mlximg *bg,
					t_mlximg *asset);
void			update_used_player_sprite(t_gamestate *st, t_action move);

#endif
