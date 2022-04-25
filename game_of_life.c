/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:15 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/25 13:33:25 by pvillena         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

char	get_current_pos(char **map, int i, int j)
{
	int	str_len;
	int	nbr_rows;

	str_len = ft_strlen(map[i]) - 1;
	nbr_rows = ft_nbr_rows(map) - 1;
	if (j == 0 && i == 0)
		return (top_left_corner(i, j, map));
	else if (i == 0 && j > 0 && j < str_len)
		return (top_row(i, j, map));
	else if (j == str_len && i == 0)
		return (top_right_corner(i, j, map));
	else if (i > 0 && j == 0 && i < nbr_rows)
		return (left_column(i, j, map));
	else if (i > 0 && i < nbr_rows && j == str_len)
		return (right_column(i, j, map));
	else if (j == 0 && i == nbr_rows)
		return (bottom_left_corner(i, j, map));
	else if (i == nbr_rows && j > 0 && j < str_len)
		return (bottom_row(i, j, map));
	else if (i == nbr_rows && j == str_len)
		return (bottom_right_corner(i, j, map));
	else if (i > 0 && i < nbr_rows && j > 0 && j < str_len)
		return (every_other_case(i, j, map));
	return ('0');
}

void	game_of_life(t_vars *vars)
{
	char	**next_gen;
	int		str_len;
	int		i;
	int		j;

	str_len = ft_strlen(vars->map[0]);
	next_gen = (char **)malloc(sizeof(char *) * (str_len + 1));
	i = -1;
	while (vars->map[++i])
		next_gen[i] = (char *)malloc(sizeof(char) * (str_len + 1));
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[j])
		{
			next_gen[i][j] = get_current_pos(vars->map, i, j);
			j++;
		}
		next_gen[i][j] = 0;
		i++;
	}
	next_gen[i] = NULL;
	free_machine(vars->map);
	vars->map = next_gen;
	usleep(25000);
	paint_map(*vars);
}
