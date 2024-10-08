/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:44:11 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:37:04 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_scaled_player_asset(t_gamestate *st, t_dir dir);

void	destroy_player_assets(t_gamestate *st)
{
	mlximg_destroy(st->mlx, &st->assets.player[UP].base);
	mlximg_destroy(st->mlx, &st->assets.player[DOWN].base);
	mlximg_destroy(st->mlx, &st->assets.player[LEFT].base);
	mlximg_destroy(st->mlx, &st->assets.player[RIGHT].base);
	mlximg_destroy(st->mlx, &st->assets.player_on_exit[UP].base);
	mlximg_destroy(st->mlx, &st->assets.player_on_exit[DOWN].base);
	mlximg_destroy(st->mlx, &st->assets.player_on_exit[LEFT].base);
	mlximg_destroy(st->mlx, &st->assets.player_on_exit[RIGHT].base);
	destroy_scaled_player_asset(st, UP);
	destroy_scaled_player_asset(st, DOWN);
	destroy_scaled_player_asset(st, LEFT);
	destroy_scaled_player_asset(st, RIGHT);
}
