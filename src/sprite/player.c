/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:22:39 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:36:54 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_player_assets_dir(t_gamestate *st, t_dir dir)
{
	t_img	tmp;

	mlximg_from_xpm(st->mlx, "textures/pacMan.xpm",
		&st->assets.player[dir].base);
	img_clone(imgview(&st->assets.player[dir].base.img), &tmp);
	if (dir == LEFT)
		imgview_flip_h(imgview(&st->assets.player[dir].base.img));
	else if (dir == UP)
		imgview_rotate90(imgview(&tmp),
			imgview(&st->assets.player[dir].base.img));
	else if (dir == DOWN)
		imgview_rotate270(imgview(&tmp),
			imgview(&st->assets.player[dir].base.img));
	img_destroy(&tmp);
	mlximg_clone(st->mlx, imgview(&st->assets.player[dir].base.img),
		&st->assets.player_on_exit[dir].base);
	blend_asset_with_bg(st, &st->assets.exit.base,
		&st->assets.player_on_exit[dir].base);
	blend_asset_with_bg(st, &st->assets.floor.base,
		&st->assets.player[dir].base);
}

void	destroy_scaled_player_asset(t_gamestate *st, t_dir dir)
{
	mlximg_destroy(st->mlx, &st->assets.player[dir].scaled);
	mlximg_destroy(st->mlx, &st->assets.player_on_exit[dir].scaled);
}

static void	update_scaled_player_asset(t_gamestate *st, t_dir dir)
{
	destroy_scaled_player_asset(st, dir);
	mlximg_clone_scaled(st->mlx, imgview(&st->assets.player[dir].base.img),
		st->opts.scale, &st->assets.player[dir].scaled);
	mlximg_clone_scaled(st->mlx,
		imgview(&st->assets.player_on_exit[dir].base.img), st->opts.scale,
		&st->assets.player_on_exit[dir].scaled);
}

void	update_scaled_player_assets(t_gamestate *st)
{
	update_scaled_player_asset(st, UP);
	update_scaled_player_asset(st, DOWN);
	update_scaled_player_asset(st, LEFT);
	update_scaled_player_asset(st, RIGHT);
}

void	load_player_assets(t_gamestate *st)
{
	load_player_assets_dir(st, UP);
	load_player_assets_dir(st, DOWN);
	load_player_assets_dir(st, LEFT);
	load_player_assets_dir(st, RIGHT);
	update_scaled_player_assets(st);
}
