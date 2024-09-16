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

void	free_va(size_t count, ...)
{
	va_list	args;
	void	*ptr;
	void	**address;

	va_start(args, count);
	while (count--)
	{
		ptr = va_arg(args, void *);
		address = &ptr;
		ft_nfree(address);
	}
	va_end(args);
}
