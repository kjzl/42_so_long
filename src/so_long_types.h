/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:41:51 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 05:34:03 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_TYPES_H
# define SO_LONG_TYPES_H

# include "../libft/libft.h"

# define ENEMY_VARIANTS 5

# ifdef BONUS
typedef enum	e_tile {
	EMPTY = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	START = 'P',
	ENEMY = 'X'
}	t_tile;
# else
typedef enum	e_tile {
	EMPTY = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	START = 'P'
}	t_tile;
# endif

typedef struct	s_level {
	union {
		t_size		size;
		struct {
			size_t	width;
			size_t	height;
		};
	};
	char			**tiles;
}					t_level;

typedef struct	s_levelinfo
{
	/// t_vec<t_pos>
	t_vec		coins;
	t_upoint	start;
	t_upoint	exit;
	int			errs;
}			t_levelinfo;

typedef struct	s_sprite {
	/// vec<t_mlximg>
	t_vec		imgs;
	/// Ticks per img
	uint32_t	img_ticks;
}				t_sprite;

typedef struct	s_assets {
	t_sprite	empty;
	t_sprite	wall;
	t_sprite	exit;
	t_sprite	coin;
	t_sprite	big_coin;
	t_sprite	player[4];
	t_sprite	enemy[ENEMY_VARIANTS][4];
}			t_assets;

typedef enum	s_gamestatus {
	PREGAME,
	PLAYING,
	PAUSED,
	WON,
	LOST,
}				t_gamestatus;

typedef struct	s_gamestate {
	void			*mlx;
	void			*mlx_win;
	t_size			win_size;
	t_mlximg		win_img;
	t_mlximg		win_img_buf;
	t_assets	base_textures;
	/// scaled textures
	t_assets	assets;
	t_gameopts		opts;
	t_level			level;
	t_gamestatus	status;
	t_upoint		cam_offset;
	size_t			step;
	t_entity		player;
	/// t_vec<t_entity>
	t_vec			enemies;
	/// t_vec<t_object>
	t_vec			coins;
}					t_gamestate;

typedef enum	e_cam_mode {
	CENTER_PLAYER,
	CENTER_MAP,
}	t_cam_mode;

typedef struct	s_gameopts {
	size_t		cam_deadzone;
	size_t		scale;
	t_cam_mode	cam_mode;
	t_bool		can_change_cam_mode;
}				t_gameopts;

typedef struct	s_object {
	/// Level/Tile position
	t_upoint		tile_pos;
	/// Pixel offset to tile_pos
	t_point			px_offset;
	/// Absolute pixel position (0,0 is the first pixel of the first tile)
	t_upoint		px_pos;
	/// Bounding box (absolute pixel positions)
	t_urect			bounding_box;
}					t_object;

typedef struct	s_entity {
	t_vec		*sprites;
	t_object	object;
	size_t		moves;
	size_t		score;
	size_t		death_animation;
	t_bool		is_player;
	t_dir		dir;
}				t_entity;

typedef enum	e_dir {
	RIGHT,
	LEFT,
	UP,
	DOWN,
}				t_dir;

#endif
