#include "../cub3D.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	cleanup(t_cubed *cubed)
{
	free_map(cubed->map);
}
