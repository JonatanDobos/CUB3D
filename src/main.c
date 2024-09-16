#include "../cub3D.h"

int	main(int argc, char **argv)
{
	t_cubed	cubed;

	if (argc != 2 || check_map(&cubed, argv[1]))
		return (printf("Usage: %s %s\n", argv[0], PROMPT), EXIT_FAILURE);
	test_print_map(&cubed, 0);
	cleanup(&cubed);
	return (EXIT_SUCCESS);
}
