/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:12:44 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/25 16:45:06 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	validate_level_iter(t_upoint pos, t_upoint x_y_max, uint8_t tile,
		void *info)
{
	t_levelinfo	*level_info;

	level_info = (t_levelinfo *)info;
	if (pos_is_on_edge(pos, x_y_max) && tile != WALL)
		level_info->errs |= ERR_LEVEL_NO_WALLS;
	if (tile == COIN)
		vec_push(&level_info->coins, &pos);
	else if (tile == START)
	{
		if (level_info->start.x != 0 || level_info->start.y != 0)
			level_info->errs |= ERR_LEVEL_MULTI_START;
		level_info->start = pos;
	}
	else if (tile == EXIT)
	{
		if (level_info->exit.x != 0)
			level_info->errs |= ERR_LEVEL_MULTI_EXIT;
		level_info->exit = pos;
	}
	else if (tile != WALL && tile != FLOOR)
		level_info->errs |= ERR_LEVEL_UNRECOGNIZED_TILE;
}

/// @brief This function will scan the level to remove reachable coins
/// from the level_info and check if the exit is reachable.
/// @note This function will unset the ERR_LEVEL_UNREACHABLE_EXIT flag
/// on level_info.err if the exit is reachable.
/// @param level The level to scan (scanned positions will be set to 0).
/// @param info The level_info to remove reachable coins from and set the errs.
/// @param pos The position to start the flood fill from.
static void	flood_fill(t_level *level, t_levelinfo *info, t_upoint pos)
{
	if (level->tiles[pos.y][pos.x] == ' ' || level->tiles[pos.y][pos.x] == WALL)
		return ;
	if (level->tiles[pos.y][pos.x] == COIN)
		vec_remove_last_n(&info->coins, &pos, 1);
	else if (level->tiles[pos.y][pos.x] == EXIT)
		info->errs &= ~ERR_LEVEL_UNREACHABLE_EXIT;
	level->tiles[pos.y][pos.x] = ' ';
	flood_fill(level, info, (t_upoint){pos.x - 1, pos.y});
	flood_fill(level, info, (t_upoint){pos.x + 1, pos.y});
	flood_fill(level, info, (t_upoint){pos.x, pos.y - 1});
	flood_fill(level, info, (t_upoint){pos.x, pos.y + 1});
}

/// @brief
/// @param level
/// @param info
/// @note On error the level will be replaced with the flood filled level.
/// @return
static t_bool	validate_level_win_path(const t_level *level, t_levelinfo *info)
{
	t_levelinfo	info_copy;
	t_level		level_copy;

	if (!level_clone(level, &level_copy))
		return (FALSE);
	if (!level_info_clone(info, &info_copy))
	{
		level_destroy(&level_copy);
		return (FALSE);
	}
	info_copy.errs |= ERR_LEVEL_UNREACHABLE_EXIT;
	flood_fill(&level_copy, &info_copy, info_copy.start);
	if (info_copy.errs)
		ft_memswap((t_level *)level, &level_copy, sizeof(t_level));
	info->errs = info_copy.errs;
	if (info_copy.coins.len != 0)
		info->errs |= ERR_LEVEL_UNREACHABLE_COINS;
	level_info_destroy(&info_copy);
	level_destroy(&level_copy);
	return (info->errs == 0);
}

t_bool	validate_level(const t_level *level, t_levelinfo *out_info)
{
	*out_info = level_info_empty();
	level_iter(level, validate_level_iter, out_info);
	if (out_info->start.x == 0)
		out_info->errs |= ERR_LEVEL_NO_START;
	if (out_info->exit.x == 0)
		out_info->errs |= ERR_LEVEL_NO_EXIT;
	if (out_info->coins.len == 0 && !out_info->coins.mem_err)
		out_info->errs |= ERR_LEVEL_NO_COINS;
	if (out_info->errs || out_info->coins.mem_err)
		return (FALSE);
	return (validate_level_win_path(level, out_info));
}
