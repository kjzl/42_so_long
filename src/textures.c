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

#include "so_long.h"

void	destroy_img_vec(void *mlx, t_vec *vec)
{
	vec_iteri(vec, iteri_img_destroy, mlx);
	vec_destroy(vec, 0);
}

void	destroy_textures(void *mlx, t_assets *assets)
{
	size_t	i_dir;
	size_t	i_enemy;

	img_destroy(mlx, &assets->empty);
	img_destroy(mlx, &assets->wall);
	img_destroy(mlx, &assets->exit);
	destroy_img_vec(mlx, &assets->coin);
	destroy_img_vec(mlx, &assets->big_coin);
	i_dir = 0;
	while (i_dir < 4)
		destroy_img_vec(mlx, &assets->player[i_dir++]);
	i_dir = 0;
	i_enemy = 0;
	while (i_enemy < ENEMY_VARIANTS)
	{
		while (i_dir < 4)
			destroy_img_vec(mlx, &assets->enemy[i_enemy][i_dir++]);
		i_enemy++;
	}
}

static t_bool	img_vec_rotate_imgs_dir(void *mlx, t_vec *src, t_vec *out, t_dir dir)
{
	size_t i;

	i = 0;
	*out = vec_empty_with_capacity(sizeof(t_img), src->len);
	if (out->mem_err)
		return (FALSE);
	if ()
	{
		while (i < src->len)
		{
			mlximg_clone_scaled(mlx, vec_get_at(src, dir), 1,
				vec_get_next_uninit_incr_len(out));
			if (dir == LEFT)
				imgview_flip_h(img_as_rect(vec_get_at(out, i)));
			else if (dir == UP)
				img_rect_rotate270(img_as_rect(vec_get_at(out, i)));
			else if (dir == DOWN)
				img_rect_rotate90(img_as_rect(vec_get_at(out, i)));
			i++;
		}
	}
}

static t_bool	load_and_rotate_for_dirs(void *mlx, const char *path,
					t_vec out[4])
{
	t_bool	ok;
	t_img	tmp;

	ok = TRUE;
	if (!(img_from_xpm(mlx, path, &tmp)
		&& mlximg_split_sprite(mlx, &tmp, &out[0])))
		ok = FALSE;
	else
	{
		out[1] = vec_empty_with_capacity(sizeof(t_img), out[0].len);
		out[2] = vec_empty_with_capacity(sizeof(t_img), out[0].len);
		out[3] = vec_empty_with_capacity(sizeof(t_img), out[0].len);
		if (out[1].mem_err || out[2].mem_err || out[3].mem_err)
			ok = FALSE;
		else
		{

		}
	}

	if (!img_rotate(&out[i], ))
		ok = FALSE;
	return (ok);
}

t_bool	load_textures(void *mlx, t_assets *out)
{
	t_bool	ok;
	t_img	tmp;

	ok = TRUE;
	*out = (t_assets){0};
	if (!img_from_xpm(mlx, "assets/empty.xpm", &out->empty))
		ok = FALSE;
	if (!img_from_xpm(mlx, "assets/wall.xpm", &out->wall))
		ok = FALSE;
	if (!img_from_xpm(mlx, "assets/exit.xpm", &out->exit))
		ok = FALSE;
	if (!(img_from_xpm(mlx, "assets/coin.xpm", &tmp)
		&& mlximg_split_sprite(mlx, &tmp, &out->coin)))
		ok = FALSE;
	if (!(img_from_xpm(mlx, "assets/bigCoin.xpm", &tmp)
		&& mlximg_split_sprite(mlx, &tmp, &out->big_coin)))
		ok = FALSE;

}

static t_bool	load_enemies(void *mlx, t_assets *out)
{
	t_bool	ok;

	ok = TRUE;
	if (!img_from_xpm(mlx, "assets/yellowGhost.xpm", &out->enemy[0][RIGHT]))
		ok = FALSE;
	if (!img_from_xpm(mlx, "assets/blueGhost.xpm", &out->enemy[1][RIGHT]))
		ok = FALSE;
	if (!img_from_xpm(mlx, "assets/orangeGhost.xpm", &out->enemy[2][RIGHT]))
		ok = FALSE;
	if (!img_from_xpm(mlx, "assets/greenGhost.xpm", &out->enemy[3][RIGHT]))
		ok = FALSE;
	if (!img_from_xpm(mlx, "assets/redGhost.xpm", &out->enemy[4][RIGHT]))
		ok = FALSE;
	return (ok);
}
