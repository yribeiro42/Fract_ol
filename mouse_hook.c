/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:30:15 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/19 22:32:58 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *env, int x, int y, double factor)
{
	double apt;
	double diff;
	double offsetx;
	double offsety;

	apt = env->zoom * factor;
	diff = apt - env->zoom;
	offsetx = (((double)((HEIGHT / 2) - x) / HEIGHT) * diff);
	offsety = (((double)((HEIGHT / 2) - y) / HEIGHT) * diff);
	env->start_x += offsetx;
	env->start_y += offsety;
	env->zoom = apt;
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
	else if (button == 3 && env->iteration > 10)
		env->iteration -= 10;
	if (button == 4)
	{
		 zoom(env, x, y, 1.1);
	}
	else if (button == 5)
	{
		zoom(env, x, y, 0.9);
	}
	redraw(env);
	return (0);
}
