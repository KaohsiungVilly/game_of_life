/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:03 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/25 12:38:54 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

char	top_left_corner(int i, int j, char **map)
{
	int	count;

	count = 0;
	if (map[i] [j + 1] == '1')
		count++;
	if (map[i + 1] [j] == '1')
		count++;
	if (map[i + 1][j + 1] == '1')
		count++;
	return (calc_char(count, map[i][j]));
}

char	top_row(int i, int j, char **map)
{
	int	count;

	count = 0;
	if (map[i][j - 1] == '1')
		count++;
	if (map[i + 1][j - 1] == '1')
		count++;
	if (map[i] [j + 1] == '1')
		count++;
	if (map[i + 1] [j] == '1')
		count++;
	if (map[i + 1][j + 1] == '1')
		count++;
	return (calc_char(count, map[i][j]));
}

char	top_right_corner(int i, int j, char **map)
{
	int	count;

	count = 0;
	if (map[i][j - 1] == '1')
		count++;
	if (map[i + 1][j - 1] == '1')
		count++;
	if (map[i + 1][j] == '1')
		count++;
	return (calc_char(count, map[i][j]));
}

char	left_column(int i, int j, char **map)
{
	int	count;

	count = 0;
	if (map[i - 1][j] == '1')
		count++;
	if (map[i - 1][j + 1] == '1')
		count++;
	if (map[i][j + 1] == '1')
		count++;
	if (map[i + 1][j] == '1')
		count++;
	if (map[i + 1][j + 1] == '1')
		count++;
	return (calc_char(count, map[i][j]));
}



char	right_column(int i, int j, char **map)
{
	int	count;

	count = 0;
	if (map[i - 1][j] == '1')
		count++;
	if (map[i - 1][j - 1] == '1')
		count++;
	if (map[i][j - 1] == '1')
		count++;
	if (map[i + 1][j - 1] == '1')
		count++;
	if (map[i + 1][j] == '1')
		count++;
	return (calc_char(count, map[i][j]));
}

char	bottom_left_corner(int i, int j, char **map)
{
	int	count;

	count = 0;
	if (map[i - 1][j] == '1')
		count++;
	if (map[i - 1][j + 1] == '1')
		count++;
	if (map[i][j + 1] == '1')
		count++;
	return (calc_char(count, map[i][j]));
}

char	bottom_row(int i, int j, char **map)
{
	int	count;

	count = 0;
	if (map[i - 1][j - 1] == '1')
		count++;
	if (map[i][j - 1] == '1')
		count++;
	if (map[i - 1][j] == '1')
		count++;
	if (map[i - 1][j + 1] == '1')
		count++;
	if (map[i][j + 1] == '1')
		count++;
	return (calc_char(count, map[i][j]));
}

char	bottom_right_corner(int i, int j, char **map)
{
	int	count;

	count = 0;
	if (map[i - 1] [j - 1] == '1')
		count++;
	if (map[i - 1] [j] == '1')
		count++;
	if (map[i] [j - 1] == '1')
		count++;
	return (calc_char(count, map[i][j]));
}

char	every_other_case(int i, int j, char **map)
{
	int	count;

	count = 0;
	if (map[i - 1][j - 1] == '1')
		count++;
	if (map[i][j - 1] == '1')
		count++;
	if (map[i + 1][j - 1] == '1')
		count++;
	if (map[i - 1][j] == '1')
		count++;
	if (map[i - 1][j + 1] == '1')
		count++;
	if (map[i][j + 1] == '1')
		count++;
	if (map[i + 1][j] == '1')
		count++;
	if (map[i + 1][j + 1] == '1')
		count++;
	return (calc_char(count, map[i][j]));
}
