/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:56:22 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/25 16:40:35 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# pragma once

# include "../so_long.h"

# define ERR_LEVEL_NO_RECT				0b0000000001
# define ERR_LEVEL_UNRECOGNIZED_TILE	0b0000000010
# define ERR_LEVEL_MULTI_START			0b0000000100
# define ERR_LEVEL_NO_START				0b0000001000
# define ERR_LEVEL_MULTI_EXIT			0b0000010000
# define ERR_LEVEL_NO_EXIT				0b0000100000
# define ERR_LEVEL_NO_WALLS				0b0001000000
# define ERR_LEVEL_NO_COINS				0b0010000000
# define ERR_LEVEL_UNREACHABLE_COINS	0b0100000000
# define ERR_LEVEL_UNREACHABLE_EXIT		0b1000000000

t_bool	parse_map(int fd, t_level *out, t_levelinfo *out_info);
t_bool	validate_level(const t_level *level, t_levelinfo *out_info);

#endif
