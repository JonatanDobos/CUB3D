#include "../cub3D.h"

int	main(int argc, char **argv)
{
	t_cubed	cubed;

	if (map_check(&cubed, argv[1], argc))
		return (EXIT_FAILURE);
	test_print_map(&cubed, 0);
	cleanup(&cubed);
	return (EXIT_SUCCESS);
}
