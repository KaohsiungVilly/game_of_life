#include "game_of_life.h"

void	leaks(void)
{
	system("leaks game_of_life");
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	//atexit(leaks);
	if (argc != 2)
		return (1);
	vars = init_vars(argv);
	print_map(vars.map);
	
	game_of_life(vars);
	mlx_loop(vars.mlx);
	//free_machine(vars.map);
	return (0);
}
