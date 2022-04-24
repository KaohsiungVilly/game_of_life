#include "game_of_life.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	free_machine(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
}

static char	**append_line(char **map, char *line)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map[i++]);
	new_map = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (map[++i])
		new_map[i] = map[i];
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

char	**get_map(char *argv[])
{
	char	**map;
	int		fd;
	int		count_lines;

	count_lines = 0;
	fd =  open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (1);
	map = (char **)malloc(sizeof(char *) * 2);
	map[count_lines] = get_next_line(fd);
	if (map[count_lines] == NULL)
		exit(1);
	map[count_lines + 1] = NULL;
	count_lines = -1;
	while (map[++count_lines])
		map = append_line(map, get_next_line(fd));
	map[count_lines] = NULL;
	return (map);
}
