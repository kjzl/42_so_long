/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:41:51 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/20 23:07:08 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_TYPES_H
# define SO_LONG_TYPES_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>

typedef struct s_pos {
	size_t	x;
	size_t	y;
}			t_pos;

typedef struct s_level {
	char	**tiles;
	size_t	width;
	size_t	height;
}			t_level;

typedef enum e_tile {
	EMPTY = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	START = 'P'
}		t_tile;

typedef struct s_level_info
{
	/// t_vec<t_pos>
	t_vec		coins;
	t_pos		start;
	t_pos		exit;
	int			errs;
}			t_level_info;

#endif
