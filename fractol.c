#include "fractol.h"

void	usage(void)
{
	write(1, "Usage: ./fractol #\n 1: Mandelbrot\n 2:Julia\n 3:Burning Ship", 58);
}

int main(int argc, char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	init_env(env);
	create_env(env);
	init_burningship(env);
	draw_burningship(env);
	mlx_key_hook(env->win, key_hook, env);
	destroy_env(env);
	mlx_loop(env->mlx);
	return (0);
}