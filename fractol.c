#include "fractol.h"

void	usage(void)
{
	write(1, "Usage: ./fractol #\n 1: Mandelbrot\n"
	 			" 2: Julia\n 3: Burning Ship\n", 61);
	exit(0);
}

void	fractol(t_env *env, char fractal)
{
	if (env->fractal == '1')
		draw_mandelbrot(env);
	else if (env->fractal == '2')
		draw_julia(env);
	else
		draw_burningship(env);
}

int main(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2)
		usage();
	env = malloc(sizeof(t_env));
	init_env(env);
	create_env(env);
	if (argv[1][0] == '1' || argv[1][0] == '2' || argv[1][0] == '3')
	{
		env->fractal = argv[1][0];
		fractol(env, env->fractal);
	}
	else
		usage();
	draw_image(env);
 	mlx_key_hook(env->win, key_press_hook, env);
 	mlx_mouse_hook(env->win, mouse_button_hook, env);
 	//set_hooks(env);
	mlx_loop(env->mlx);
	return (0);
}
