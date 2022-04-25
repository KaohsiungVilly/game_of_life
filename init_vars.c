/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:23 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/25 18:09:45 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

t_vars	init_vars(char *argv[])
{
	t_vars	vars;

	vars.map = get_map(argv);
	vars = get_scrn_size(vars);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, vars.scrn.width, vars.scrn.height, "game of life");
	vars.img.img = mlx_new_image(vars.mlx, vars.scrn.width, vars.scrn.height);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img_b.endian);
	vars.sleep = 25000;
	return (vars);
}
