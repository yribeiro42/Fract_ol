#include "fractol.h"

void	init_mandelbrot(t_env *env)
{
	env->start_x = -0.5;
	env->start_y = 0.0;
	env->zoom = 1;
	env->iteration = 300                                                                               ;
	env->color = 0xFFAA7F;
	env->flag = 1;
}

int		mandelbrot(t_env *env)
{
	t_complex	new;
	t_complex	old;
	int			i;
	
	new.real = 0;
	new.imag = 0;
	i = 0;
	while ((new.real * new.real + new.imag * new.imag) < 4.0 && i < env->iteration)
	{
		old.real = new.real;
		old.imag = new.imag;
		new.real = old.real * old.real - old.imag * old.imag + env->p_r;
		new.imag = 2.0 * old.real * old.imag + env->p_i;
		i++;
	}
	if (i == env->iteration)
		return (0);
	return (i);
}

void	draw_mandelbrot(t_env *env)
{
	if (!env->flag)
		init_mandelbrot(env);
	int	x;
	int	y;
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
			fill_pixel(env, x, y, color);
			x++;
		}
		y++;
	}
}