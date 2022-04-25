/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:26 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/25 18:13:28 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

int	key_hooks(int keycode, t_vars *vars)
{
	if (keycode == 126 && vars->sleep >= 1000)
		vars->sleep -= 1000;
	if (keycode == 125 && vars->sleep < 50000)
		vars->sleep += 1000;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	game_of_life(vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		return (1);
	vars = init_vars(argv);
	paint_map(vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_hook(vars.mlx_win, 2, 1L<<0, key_hooks, &vars);
	mlx_loop(vars.mlx);
	exit(0);
}
