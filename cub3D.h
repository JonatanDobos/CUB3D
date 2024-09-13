#ifndef CUB_H
# define CUB_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include "../libft/libft.h"

# define PROMPT "map_file"

typedef struct s_mlx_data
{
	mlx_t		*instance;
	mlx_image_t	*img;
}	t_mlx_data;

typedef struct s_cubed
{
	int			map_fd;
	char		**map;
	t_mlx_data	mlx;
}	t_cubed;

bool	check_map(t_cubed *cubed, char *map);
void	cleanup(t_cubed *cubed);

#endif