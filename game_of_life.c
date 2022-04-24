#include "game_of_life.h"

char	get_current_pos(char **map, int i, int j)
{
	int	count;
	int	str_len;
	int	nbr_rows;

	count = 0;
	str_len = ft_strlen(vars.map[i]) - 1;
	nbr_rows = nbr_rows(vars.map) - 1;
	if (j == 0 && i == 0) //left corner
	{
		
	}
	else if (i == 0 && j > 0 && j < str_len) // top row
	{

	}
	else if (j == str_len && i == 0) // right corner
	{

	}
	else if (i > 0 && j == 0 && i < nbr_rows) // left column
	{

	}
	else if (i > 0 && i < nbr_rows && j == str_len) // right column
	{

	}
	else if (j == 0 && i == nbr_rows) // left bottom corner
	{

	}
	else if (i == nbr_rows && j > 0 && j < str_len) // bottom row
	{

	}
	else if (i == nbr_rows && j == str_len) // bottom right corner
	{

	}
	else
	{

	}
}

void	game_of_life(t_vars vars)
{
	char	**next_gen;
	int		i;
	int		j;

	paint_map(vars);
	next_gen = (char **)malloc(sizeof(char *) * (nbr_rows(vars.map) + 1));
	i = 0;
	while (vars.map[i])
	{
		j = 0;
		while (vars.map[j])
		{
			next_gen[i][j++] = get_current_pos(vars.map, i, j);
		}
	}
}
