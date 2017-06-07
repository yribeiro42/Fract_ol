#include "fractol.h"

void	fill_pixel(t_env *env, int x, int y, int hexcolor)
{
	int pos;

	pos = (4 * x) + (4 * y * WIDTH);
	env->img_str[pos] = hexcolor;
 	env->img_str[pos + 1] = hexcolor >> 8;
	env->img_str[pos + 2] = hexcolor >> 16;
}

void	redraw(t_env *env)
{
	if (env->fractal == '1')
		env->fractal_ptr = draw_mandelbrot;
	else if (env->fractal == '2')
		env->fractal_ptr = draw_julia;
	else if (env->fractal == '3')
		env->fractal_ptr = draw_burningship;
}
