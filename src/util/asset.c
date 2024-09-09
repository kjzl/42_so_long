#include "util.h"

void	load_asset_with_bg(t_gamestate *st, t_mlximg *bg, const char *path, t_mlximg *out)
{
	t_mlximg	tmp;

	mlximg_clone(st->mlx, imgview(&bg->img), out);
	mlximg_from_xpm(st->mlx, path, &tmp);
	imgview_blend(imgview(&tmp.img), imgview(&out->img));
	mlximg_destroy(st->mlx, &tmp);
}
