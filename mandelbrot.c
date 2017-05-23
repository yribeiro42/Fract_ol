#include "fractol.h"

void	init_mandelbrot(t_env *env)
{
	env->start_x = -0.75;
	env->start_y = 0.0;
	env->zoom = 0.8;
	env->iteration = 30;
	env->new_r = 0;
	env->new_i = 0;
	env->old_r = 0;
	env->old_i = 0;
	env->color = 0x00AA7F;
}

int		mandelbrot(t_env *env)
{
	int			i;
	t_complex	new;
	t_complex	old;

	new.r = 0;
	new.i = 0;
	i = 0;
	while ((new.r * new.r + new.i * new.i) < 4.0 && i < env->iteration)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + env->p_r;
		new.i = 2.0 * old.r * old.i + env->p_i;
		i++;
	}
	if (i == env->iteration)
		return (0);
	return (i);
}

void	draw(t_env *env)
{
	int	x;
	int	y;
	int i;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		env->p_i = (y - HEIGHT / 2.0) / (0.5 * env->zoom * HEIGHT) + env->start_y;
		x = 0;
		while (x < WIDTH)
		{
			env->p_r = 1.5 * (x - WIDTH / 2.0) / (0.5 * env->zoom * WIDTH) + env->start_x;
			color = (env->color * (mandelbrot(env) % 255));
			//printf("color = %d\n", color);
			fill_pixel(env, x, y, color);
			x++;
		}
		y++;
	}
}