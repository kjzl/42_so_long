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
# define SPRITE_SIZE 16
# define SCALE_MAX 4

# ifdef BONUS

typedef enum e_tile
{
	FLOOR = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	START = 'P',
	ENEMY = 'X'
}						t_tile;

# else

typedef enum e_tile
{
	FLOOR = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	START = 'P'
}						t_tile;

# endif

typedef struct s_level
{
	union
	{
		t_size			size;
		struct
		{
			uint32_t	width;
			uint32_t	height;
		};
	};
	uint8_t				**tiles;
}						t_level;

typedef struct s_levelinfo
{
	/// t_vec<t_upoint>
	t_vec				coins;
	t_upoint			start;
	t_upoint			exit;
	int					errs;
}						t_levelinfo;

typedef struct s_mlximg
{
	void				*mlxdata;
	t_img				img;
}						t_mlximg;

typedef struct s_sprite
{
	t_mlximg			base;
	t_mlximg			scaled;
}						t_sprite;

// typedef struct s_anim_sprite
// {
// 	t_sprite	*base;
// 	t_sprite	*scaled;
// 	size_t		frames;
// }				t_anim_sprite;

typedef struct s_assets
{
	t_sprite			floor;
	t_sprite			wall;
	t_sprite			exit;
	t_sprite			coin;
	t_sprite			big_coin;
	t_sprite			player[4];
	t_sprite			player_on_exit[4];
}						t_assets;

typedef enum e_gamestatus
{
	PREGAME,
	PLAYING,
	WON,
	LOST,
}						t_gamestatus;

typedef enum e_cam_mode
{
	CENTER_PLAYER,
	CENTER_MAP,
}						t_cam_mode;

typedef struct s_gameopts
{
	size_t				scale;
	t_cam_mode			cam_mode;
}						t_gameopts;

typedef struct s_object
{
	t_sprite			*sprite;
	t_upoint			tile;
}						t_object;

typedef struct s_entity
{
	t_object			obj;
}						t_entity;

typedef struct s_player
{
	union
	{
		t_entity		entity;
		struct
		{
			t_object	obj;
		};
	};
	int32_t				moves;
	int32_t				score;
}						t_player;

typedef enum e_dir
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
}						t_dir;

typedef struct s_gamestate
{
	void				*mlx;
	void				*mlx_win;
	t_size				win_size;
	t_assets			assets;
	t_level				level;
	t_levelinfo			levelinfo;
	t_gameopts			opts;
	t_gamestatus		status;
	t_point				cam_offset;
	t_player			player;
	/// t_vec<t_object>
	t_vec				coins;
}						t_gamestate;

# define INPUT_ARROW_UP 65362
# define INPUT_ARROW_DOWN 65364
# define INPUT_ARROW_LEFT 65361
# define INPUT_ARROW_RIGHT 65363
# define INPUT_W 119
# define INPUT_A 97
# define INPUT_S 115
# define INPUT_D 100
# define INPUT_ESCAPE 65307
# define INPUT_Q 113
# define INPUT_R 114
# define INPUT_PLUS 43
# define INPUT_MINUS 45
# define INPUT_SPACE 32

# define ACTION_COUNT 10

typedef enum e_action
{
	ACTION_NOOP,
	ACTION_UP,
	ACTION_DOWN,
	ACTION_LEFT,
	ACTION_RIGHT,
	ACTION_EXIT,
	ACTION_RESTART,
	ACTION_ZOOM_IN,
	ACTION_ZOOM_OUT,
	ACTION_CAM_MODE_TOGGLE,
}						t_action;

#endif
