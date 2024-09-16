#include "../cub3D.h"

void	test_print_map(t_cubed *cubed, int size)
{
	int	i;

	i = 0;
	if (size)
	{
		while (i < size)
			printf("%s\n", cubed->map[i++]);
		return ;
	}
	while (cubed->map[i])
		printf("%s\n", cubed->map[i++]);
	return ;
}