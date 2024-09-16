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
# include "libft/libft.h"

# define USAGE_PROMPT "Usage: ./cub3D map_file.cub"

enum e_error
{
	OK = 0,
	FAIL = 1,
	MERR = 2
};

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

// map_check.c
bool	map_check(t_cubed *cubed, char *map_file, int argc);

// cleanup.c
void	cleanup(t_cubed *cubed);
void	free_va(size_t count, ...);

// error.c
void	e_exit_num(t_cubed *cubed, int errnum, char *msg);
void	e_exit(t_cubed *cubed, char *msg);
void	e_msg(char *msg, bool print_errno);

// _TEST.c
void	test_print_map(t_cubed *cubed, int size);

#endif