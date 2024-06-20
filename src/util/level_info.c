/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:29:01 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/20 20:12:05 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_level_info	level_info_empty(void)
{
	t_level_info	info;

	info.coins = vec_empty(sizeof(t_pos));
	info.exit = (t_pos){0};
	info.start = (t_pos){0};
	info.errs = 0;
	return (info);
}

void	level_info_destroy(t_level_info *info)
{
	vec_destroy(&info->coins, 0);
	*info = level_info_empty();
}

t_bool	level_info_clone(const t_level_info *info, t_level_info *out)
{
	*out = *info;
	out->coins = vec_clone(&info->coins);
	return (!out->coins.mem_err);
}
