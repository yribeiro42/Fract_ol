#include "fractol.h"

int		mouse_button_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
		env->iteration += 10;
	if (button == 2)
		env->iteration -= 10;
	if (button == 5)
	{
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		env->zoom = (env->zoom + 1) * 1.1;
		env->start_x += x / env->zoom / 1.5;
		env->start_y += y / env->zoom / 1.5;
	}
	return (0);
}