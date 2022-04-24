#include "game_of_life.h"

t_vars	init_vars(char *argv[])
{
	t_vars	vars;

	vars.map = get_map(argv);
	vars = get_scrn_size(vars);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, vars.scrn.width, vars.scrn.height, "game of life");
	vars.img_b.img = mlx_new_image(vars.mlx, 8, 8);
	vars.img_w.img = mlx_new_image(vars.mlx, 8, 8);
	vars.img_b.addr = mlx_get_data_addr(vars.img_b.img, &vars.img_b.bits_per_pixel, &vars.img_b.line_length, &vars.img_b.endian);
	vars.img_w.addr = mlx_get_data_addr(vars.img_w.img, &vars.img_w.bits_per_pixel, &vars.img_w.line_length, &vars.img_w.endian);
	paint_white_img(vars.img_w);
	return (vars);
}
