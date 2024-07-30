/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:33:29 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 05:53:38 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlximg/mlximg.h"
# include "so_long_types.h"
# include "util/util.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

t_bool	parse_map(int fd, t_level *out, t_levelinfo *out_info);

// typedef struct s_entity {

// }

#endif
