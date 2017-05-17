#include "fractol.h"

void	init_mandelbrot(t_env *env)
{
	env->x1 = -2.5;
	env->x2 = 1.5;
	env->y1 = -2.0;
	env->y2 = 2.0;
	env->iteration = 50;

}

int		mandelbrot(t_env *env)
{
	int			i;
	t_complex 	tmp;
	float		x;

	x = 0;
	i = 0;
	tmp.real = 0;
	tmp.imag = 0;
	while ((tmp.real * tmp.real + tmp.imag * tmp.imag) < 4 && i < iteration)
	{
		x = tmp.real;
		tmp.real = tmp.real * tmp.real - temp.imag * temp.imag + c->real;
		tmp.imag = (2.0 * x * tmp.imag) + c->imag;
		i++;
	}
	

}