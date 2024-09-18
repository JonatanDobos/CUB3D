#include "../cub3D.h"

void	init_mlx_window(t_cubed *c, char *name)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	c->mlx.instance = mlx_init(c->mlx.width, c->mlx.height, name, 0);
	if (!c->mlx.instance)
		e_exit(c, "MLX init error");
}

void	init_mlx_image(t_cubed *c)
{
	c->mlx.img = mlx_new_image(c->mlx.instance, c->mlx.width, c->mlx.height);
	if (!c->mlx.img)
		e_exit(c, "MLX image init error");
}
