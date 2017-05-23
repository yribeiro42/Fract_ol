#include "fractol.h"

int		key_hook(int key, t_env *env)
{
	if (key == ESC)
		exit(0);
	return (0);
}