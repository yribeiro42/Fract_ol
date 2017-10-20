/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:30:15 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/20 12:41:58 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *env, int x, int y, double factor)
{
	double newzoom;
	double diff;
	double offsetx;
	double offsety;

	newzoom = env->zoom * factor;
	diff = newzoom - env->zoom;
	offsetx = (((double)((WINX / 2) - x) / HEIGHT) * diff);
	offsety = (((double)((HEIGHT / 2) - y) / HEIGHT) * diff);
	printf("%f;%f\n", offsetx, offsety);
	env->start_x -= offsetx;
	env->start_y -= offsety;
	env->zoom = newzoom;
}

int		mouse_motion(int x, int y, t_env *env)
{
	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return (0);
	if (env->fractal == '2')
	{
		env->p_r = (float)(x - WIDTH / 2) / WIDTH * 2;
		env->p_i = (float)(y - HEIGHT / 2) / HEIGHT * 2;
		redraw(env);
	}
	return (0);
}

int		mouse_button_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
		env->iteration += 10;
	else if (button == 2 && env->iteration > 10)
		env->iteration -= 10;
	if (button == 4)
	{
		 zoom(env, x, y, 1.1);
		 printf("%f\n", env->zoom);
	}
	else if (button == 5)
	{
		zoom(env, x, y, 0.9);
	}
	redraw(env);
	return (0);
}
