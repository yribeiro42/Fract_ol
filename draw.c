#include "fractol.h"

void	fill_pixel(t_env *env, int x, int y, int hexcolor)
{
	int pos;

	pos = (4 * x) + (4 * y * WIDTH);
	env->img_str[pos] = hexcolor;
 	env->img_str[pos + 1] = hexcolor >> 8;
	env->img_str[pos + 2] = hexcolor >> 16;
}
