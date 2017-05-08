#include "fractol.h"

void	init_mandelbrot(t_env *env)
{
	env->x1 = -2.5;
	env->x2 = 1.5;
	env->y1 = -2.0;
	env->y2 = 2.0;

}

int		mandelbrot(t_env *env)
{
	int			i;
	t_complex 	tmp;

	i = 0;
	

}