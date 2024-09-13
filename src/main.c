#include "../cub3D.h"

int	main(int argc, char **argv)
{
	t_cubed	cubed;

	if (argc != 2 || check_map(&cubed, argv[1]))
		return (printf("Usage: %s %s", argv[0], PROMPT), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
