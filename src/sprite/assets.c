/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:01:51 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 05:18:49 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_base_assets(t_gamestate *st)
{
	mlximg_from_xpm(st->mlx, "textures/wall.xpm", &st->assets.wall.base);
	mlximg_from_xpm(st->mlx, "textures/empty.xpm", &st->assets.floor.base);
	load_asset_with_bg(st, &st->assets.floor.base, "textures/bigCoin.xpm", &st->assets.big_coin.base);
	load_asset_with_bg(st, &st->assets.floor.base, "textures/coin.xpm", &st->assets.coin.base);
	load_asset_with_bg(st, &st->assets.floor.base, "textures/exit.xpm", &st->assets.exit.base);
	load_asset_with_bg(st, &st->assets.floor.base, "textures/pacMan.xpm", &st->assets.player.base);
	load_asset_with_bg(st, &st->assets.exit.base, "textures/pacMan.xpm", &st->assets.player_on_exit.base);
}

static void	destroy_scaled_assets(t_gamestate *st)
{
	mlximg_destroy(st->mlx, &st->assets.player.scaled);
	mlximg_destroy(st->mlx, &st->assets.wall.scaled);
	mlximg_destroy(st->mlx, &st->assets.floor.scaled);
	mlximg_destroy(st->mlx, &st->assets.exit.scaled);
	mlximg_destroy(st->mlx, &st->assets.coin.scaled);
	mlximg_destroy(st->mlx, &st->assets.big_coin.scaled);
	mlximg_destroy(st->mlx, &st->assets.player_on_exit.scaled);
}

void	update_scaled_assets(t_gamestate *st)
{
	destroy_scaled_assets(st);
	mlximg_clone_scaled(st->mlx, imgview(&st->assets.big_coin.base.img),
		st->opts.scale, &st->assets.big_coin.scaled);
	mlximg_clone_scaled(st->mlx, imgview(&st->assets.coin.base.img),
		st->opts.scale, &st->assets.coin.scaled);
	mlximg_clone_scaled(st->mlx, imgview(&st->assets.exit.base.img),
		st->opts.scale, &st->assets.exit.scaled);
	mlximg_clone_scaled(st->mlx, imgview(&st->assets.floor.base.img),
		st->opts.scale, &st->assets.floor.scaled);
	mlximg_clone_scaled(st->mlx, imgview(&st->assets.wall.base.img),
		st->opts.scale, &st->assets.wall.scaled);
	mlximg_clone_scaled(st->mlx, imgview(&st->assets.player.base.img),
		st->opts.scale, &st->assets.player.scaled);
	mlximg_clone_scaled(st->mlx, imgview(&st->assets.player_on_exit.base.img),
		st->opts.scale, &st->assets.player_on_exit.scaled);
}

void	init_assets(t_gamestate *st)
{
	load_base_assets(st);
	update_scaled_assets(st);
}

void	destroy_assets(t_gamestate *st)
{
	destroy_scaled_assets(st);
	mlximg_destroy(st->mlx, &st->assets.player.base);
	mlximg_destroy(st->mlx, &st->assets.wall.base);
	mlximg_destroy(st->mlx, &st->assets.floor.base);
	mlximg_destroy(st->mlx, &st->assets.exit.base);
	mlximg_destroy(st->mlx, &st->assets.coin.base);
	mlximg_destroy(st->mlx, &st->assets.big_coin.base);
	mlximg_destroy(st->mlx, &st->assets.player_on_exit.base);
}
