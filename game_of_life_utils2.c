/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:12 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/25 18:08:21 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

t_vars	get_scrn_size(t_vars vars)
{
	vars.scrn.height = 0;
	vars.scrn.width = ft_strlen(vars.map[0]) * 8;
	while (vars.map[vars.scrn.height++]);
	vars.scrn.height = vars.scrn.height * 8;
	return (vars);
}

int	ft_nbr_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i++]);
	return (i - 1);
}

void	paint_white_img(t_data img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			my_mlx_pixel_put(&img, 8 * x + j, 8 * y + i, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

void	paint_black_img(t_data img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			my_mlx_pixel_put(&img, 8 * x + j, 8 * y + i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	paint_map(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars.map[i])
	{
		j = 0;
		while (vars.map[i][j])
		{
			if (vars.map[i][j] == '1')
				paint_white_img(vars.img, j, i);
			else if (vars.map[i][j] == '0')
				paint_black_img(vars.img, j, i);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);
}

char	calc_char(int count, char current)
{
	if (current == '1' && (count == 2 || count == 3))
		return ('1');
	else if (current == '0' && count == 3)
		return ('1');
	else
		return ('0');
}
