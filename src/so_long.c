/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:58:58 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:41:53 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop/loop.h"
#include "printf/ft_printf.h"
#include "render/render.h"
#include "so_long.h"
#include "so_long_types.h"
#include "util/util.h"

int32_t	gamestate_destroy(t_gamestate *st)
{
	destroy_assets(st);
	if (st->mlx)
	{
		mlx_destroy_window(st->mlx, st->mlx_win);
		mlx_destroy_display(st->mlx);
	}
	level_destroy(&st->level);
	level_info_destroy(&st->levelinfo);
	vec_destroy(&st->coins, 0);
	free(st->mlx);
	*st = (t_gamestate){0};
	exit(0);
	return (0);
}

int	key_hook(int32_t keycode, t_gamestate *st)
{
	handle_input(st, keycode);
	return (0);
}

void	reset_game(t_gamestate *st)
{
	init_coins(st, &st->levelinfo);
	st->player.obj = (t_object){.sprite = &st->assets.player[RIGHT],
		.tile = st->levelinfo.start};
	st->status = PREGAME;
	st->player.moves = 0;
	st->player.score = 0;
	cam_init(st);
	render(st);
}

void	init(t_gamestate *st)
{
	st->mlx = mlx_init();
	st->mlx_win = mlx_new_window(st->mlx, st->win_size.width,
			st->win_size.height, "so_long");
	if (st->mlx == 0)
	{
		perror("mlx_init");
		exit(1);
	}
	if (st->mlx_win == 0)
	{
		perror("mlx_new_window");
		exit(1);
	}
	init_assets(st);
}

int	main(int argc, char **argv)
{
	t_gamestate	state;
	int			fd;

	state = (t_gamestate){0};
	state.opts.scale = 1;
	state.win_size = size(WIN_WIDTH, WIN_HEIGHT);
	if (argc != 2 || !strsl_ends_with(cstr_view(argv[1]), cstr_slice(".ber",
				4)))
	{
		ft_putendl_fd("Usage: ./so_long <map_file.ber>", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		return (1);
	}
	if (!parse_map(fd, &state.level, &state.levelinfo))
		gamestate_destroy(&state);
	init(&state);
	reset_game(&state);
	mlx_key_hook(state.mlx_win, key_hook, &state);
	mlx_hook(state.mlx_win, 17, 0, gamestate_destroy, &state);
	mlx_loop(state.mlx);
}
