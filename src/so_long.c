/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:58:58 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/30 05:18:49 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



// TODO: check for invalid file extension.

// structure:	create a main window image of window size and draw at 0,0
//				create a second image of window size where we draw to directly, then copy to the window image when done drawing


// static int key_hook(int keycode, void *var)
// {
// 	struct s_test *a;

// 	a = var;
// 	a->counter++;
// 	ft_printf("keycode: %6d (%u)\n", keycode, a->counter);
// 	return (0);
// }

void	test_draw_img(void *mlx, t_img *out_red)
{
	t_img_urect	middle_blue;
	t_img		small_green;

	img_empty(mlx, 600, 180, out_red);
	imgview_draw_border(img_as_rect(out_red), 0x00FFFFFF, 3);
	middle_blue = img_rect_center(out_red, 45, 45);
	imgview_fill(middle_blue, 0x000000FF);
	img_empty(mlx, 30, 30, &small_green);
	imgview_fill(img_as_rect(&small_green), 0x0000FF00);
	imgview_blend(middle_blue, img_as_rect(&small_green), (t_point){-15, -15});
	imgview_blend(middle_blue, img_as_rect(&small_green), (t_point){75, -15});
	imgview_blend(middle_blue, img_as_rect(&small_green), (t_point){-15, 75});
	imgview_blend(middle_blue, img_as_rect(&small_green), (t_point){75, 75});
	imgview_blend(middle_blue, img_as_rect(&small_green), (t_point){30, 30});
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_spos){-15, -15}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_spos){75, -16}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_spos){-16, 76}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_spos){76, 75}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_spos){30, 30}, 2);
	// img_empty(mlx, 1, 1, &small_green);
	// imgview_fill(img_as_rect(&small_green), 0x0000FF00);
	// // imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_spos){0, 0}, 1);
	// // imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_spos){4, 1}, 1);
	// // imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_spos){8, 2}, 1);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+0 - 1, -10 + 24}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+2 - 1, -10 + 23}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+4 - 1, -10 + 22}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+6 - 1, -10 + 21}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+9 - 1, -10 + 20}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){11 - 1, -10 + 19}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){13 - 1, -10 + 18}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){15 - 1, -10 + 17}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){17 - 1, -10 + 16}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){20 - 1, -10 + 15}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){23 - 1, -10 + 14}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){26 - 1, -10 + 13}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){29 - 1, -10 + 12}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){32 - 1, -10 + 11}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){35 - 1, -10 + 10}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){38 - 1, -10 + 9}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){41 - 1, -10 + 8}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){44 - 1, -10 + 7}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){47 - 1, -10 + 6}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+0, -10 + 10 + 24}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+2, -10 + 10 + 23}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+4, -10 + 10 + 22}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+6, -10 + 10 + 21}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+9, -10 + 10 + 20}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){11, -10 + 10 + 19}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){13, -10 + 10 + 18}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){15, -10 + 10 + 17}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){17, -10 + 10 + 16}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){20, -10 + 10 + 15}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){23, -10 + 10 + 14}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){26, -10 + 10 + 13}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){29, -10 + 10 + 12}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){32, -10 + 10 + 11}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){35, -10 + 10 + 10}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){38, -10 + 10 + 9}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){41, -10 + 10 + 8}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){44, -10 + 10 + 7}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){47, -10 + 10 + 6}, 3);

	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+0 - 1, -10 + 21 + 24}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+2 - 1, -10 + 21 + 23}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+4 - 1, -10 + 21 + 22}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+6 - 1, -10 + 21 + 21}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+9 - 1, -10 + 21 + 20}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){11 - 1, -10 + 21 + 19}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){13 - 1, -10 + 21 + 18}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){15 - 1, -10 + 21 + 17}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){17 - 1, -10 + 21 + 16}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){20 - 1, -10 + 21 + 15}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){23 - 1, -10 + 21 + 14}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){26 - 1, -10 + 21 + 13}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){29 - 1, -10 + 21 + 12}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){32 - 1, -10 + 21 + 11}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){35 - 1, -10 + 21 + 10}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){38 - 1, -10 + 21 + 9}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){41 - 1, -10 + 21 + 8}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){44 - 1, -10 + 21 + 7}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){47 - 1, -10 + 21 + 6}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+0, -10 + 10 + 21 + 24}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+2, -10 + 10 + 21 + 23}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+4, -10 + 10 + 21 + 22}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+6, -10 + 10 + 21 + 21}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){+9, -10 + 10 + 21 + 20}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){11, -10 + 10 + 21 + 19}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){13, -10 + 10 + 21 + 18}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){15, -10 + 10 + 21 + 17}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){17, -10 + 10 + 21 + 16}, 2);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){20, -10 + 10 + 21 + 15}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){23, -10 + 10 + 21 + 14}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){26, -10 + 10 + 21 + 13}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){29, -10 + 10 + 21 + 12}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){32, -10 + 10 + 21 + 11}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){35, -10 + 10 + 21 + 10}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){38, -10 + 10 + 21 + 9}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){41, -10 + 10 + 21 + 8}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){44, -10 + 10 + 21 + 7}, 3);
	// imgview_blend_scaled(middle_blue, img_as_rect(&small_green), (t_point){47, -10 + 10 + 21 + 6}, 3);
	// // imgview_draw_border(middle_blue, 0x00FFFFFF, 1);
	// // imgview_flip_h(middle_blue);
	// // img_rect_flip_v(middle_blue);

	// t_img_urect middle_blue90 = img_rect_at(out_red, (t_upoint){middle_blue.to.x + 2, middle_blue.from.y}, middle_blue.width, middle_blue.height);
	// imgview_blend_scaled(middle_blue90, middle_blue, (t_point){0}, 1);
	// img_rect_rotate90(middle_blue90);

	// t_img_urect middle_blue180 = img_rect_at(out_red, (t_upoint){middle_blue90.to.x + 2, middle_blue90.from.y}, middle_blue90.width, middle_blue90.height);
	// imgview_blend_scaled(middle_blue180, middle_blue90, (t_point){0}, 1);
	// img_rect_rotate90(middle_blue180);

	// t_img_urect middle_blue270 = img_rect_at(out_red, (t_upoint){middle_blue180.to.x + 2, middle_blue180.from.y}, middle_blue180.width, middle_blue180.height);
	// imgview_blend_scaled(middle_blue270, middle_blue180, (t_point){0}, 1);
	// img_rect_rotate90(middle_blue270);

	// t_img_urect middle_blue360 = img_rect_at(out_red, (t_upoint){middle_blue270.to.x + 2, middle_blue270.from.y}, middle_blue270.width, middle_blue270.height);
	// imgview_blend_scaled(middle_blue360, middle_blue270, (t_point){0}, 1);
	// img_rect_rotate90(middle_blue360);

	img_destroy(mlx, &small_green);
}

int main(int argc, char **argv)
{
	t_level			level;
	t_levelinfo	info;
	int				fd;
	void	*mlx;
	void	*mlx_win;
	// t_img	img;

	if (argc != 2 || !strsl_ends_with(cstr_view(argv[1]), cstr_slice(".ber", 4)))
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
	if (parse_map(fd, &level, &info))
	{
		level_destroy(&level);
		level_info_destroy(&info);
		ft_putendl_fd("Valid ✓", 2);
	}
	else
	{
		level_destroy(&level);
		level_info_destroy(&info);
		return (1);
	}
	mlx = mlx_init();
	t_img img;
	img.mlx_img = mlx_new_image(mlx, 1920, 1080);
	int bpp;
	int line_length;
	int endian;
	img.pixels = (int *)mlx_get_data_addr(img.mlx_img, &bpp, &line_length, &endian);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// ft_printf("bpp: %d\n", img.bits_per_pixel);
	// ft_printf("line_length: %d\n", img.line_length);
	// ft_printf("endian: %d\n", img.endian);
	// my_mlx_square_put(&img, (t_pos){0, 0}, (t_pos){500, 500}, (t_color){0x00, 0xFF, 0xFF, 0x00}.color);
	// my_mlx_square_put(&img, (t_pos){10, 0}, (t_pos){20, 40}, (t_color){0xFF, 0x00, 0x00, 0b00000000}.color);
	// my_mlx_square_put(&img, (t_pos){20, 0}, (t_pos){30, 40}, (t_color){0xFF, 0x00, 0x00, 0b00000011}.color);
	// my_mlx_square_put(&img, (t_pos){30, 0}, (t_pos){40, 40}, (t_color){0xFF, 0x00, 0x00, 0b00001111}.color);
	// my_mlx_square_put(&img, (t_pos){40, 0}, (t_pos){50, 40}, (t_color){0xFF, 0x00, 0x00, 0b00111111}.color);
	// my_mlx_square_put(&img, (t_pos){50, 0}, (t_pos){60, 40}, (t_color){0xFF, 0x00, 0x00, 0b11111111}.color);
	// my_mlx_square_put(&img, (t_pos){20, 20}, (t_pos){30, 60}, (t_color){0x00, 0xFF, 0x00, 0x00}.color);
	// my_mlx_square_put(&img, (t_pos){100, 200}, (t_pos){120, 240}, (t_color){0x00, 0x00, 0xFF, 0x00}.color);
	// my_mlx_square_put(&img, (t_pos){100, 210}, (t_pos){90, 190}, (t_color){0xFF, 0xFF, 0xFF, 0xFF}.color);
	// my_mlx_square_put(&img, (t_pos){130, 230}, (t_pos){150, 270}, (t_color){0xFF, 0xFF, 0xFF, 0x00}.color);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	t_img test;
	test_draw_img(mlx, &test);
	mlx_put_image_to_window(mlx, mlx_win, test.mlx_img, 500, 100);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// int width;
	// int height;
	// t_img	ghost_img;
	// ghost_img.img = mlx_xpm_file_to_image(mlx, "assets/yellowGhost.xpm", &width, &height);
	// ghost_img.addr = mlx_get_data_addr(ghost_img.img, &ghost_img.bits_per_pixel, &ghost_img.line_length,
	// 							&ghost_img.endian);
	// ft_printf("bpp: %d\n", ghost_img.bits_per_pixel);
	// ft_printf("line_length: %d\n", ghost_img.line_length);
	// ft_printf("endian: %d\n", ghost_img.endian);
	// print_color(2, (t_color){.color = *(unsigned int*)ghost_img.addr});
	// mlx_put_image_to_window(mlx, mlx_win, ghost_img.img, 2000, 600);
	// struct s_test a;
	// a.counter = 0;
	// a.mlx = mlx;
	// a.mlx_win = mlx_win;
	// a.rgb_counter = 0;
	// mlx_do_key_autorepeaton(mlx);
	// mlx_hook(mlx_win, 2, 1L<<0, key_hook, &a);
	// mlx_loop_hook(mlx, loop_fn, &a);
	mlx_loop(mlx);
	return (0);
}

// TODO
// ESC -> exit
// R -> restart
// WASD -> move player
// Scroll Wheel -> change scale / camera zoom
// DestroyNotify Event
// Resize support ??
