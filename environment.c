#include "fractol.h"

void	init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Fractol");
}

void	create_env(t_env *env)
{
	int bpp;
	int size_line;
	int endian;

	env->img_ptr = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_str = mlx_get_data_addr(env->img_ptr, &bpp, &size_line, &endian);
}

void	draw_image(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img_ptr, 0, 0);
	mlx_destroy_image(env->mlx, env->img_ptr);
}

void	set_hooks(t_env *env)
{
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_hook(env->win, 2, 0, key_press_hook, env);
	mlx_hook(env->win, 4, 0, mouse_button_hook, env);
}
