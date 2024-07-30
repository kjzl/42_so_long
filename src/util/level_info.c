/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:29:01 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/25 16:45:06 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_levelinfo	level_info_empty(void)
{
	t_levelinfo	info;

	info.coins = vec_empty(sizeof(t_upoint));
	info.exit = (t_upoint){0};
	info.start = (t_upoint){0};
	info.errs = 0;
	return (info);
}

void	level_info_destroy(t_levelinfo *info)
{
	vec_destroy(&info->coins, 0);
	*info = level_info_empty();
}

t_bool	level_info_clone(const t_levelinfo *info, t_levelinfo *out)
{
	*out = *info;
	out->coins = vec_clone(&info->coins);
	return (!out->coins.mem_err);
}
