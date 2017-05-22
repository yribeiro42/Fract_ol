#include "fractol.h"

int main(int argc, char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	init_env(env);
	create_env(env);
	init_mandelbrot(env);
	draw(env);
	destroy_env(env);
	mlx_loop(env->mlx);
	return (0);
}