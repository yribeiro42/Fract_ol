/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:30:15 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/18 22:22:13 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_motion(int x, int y, t_env *env)
{
	if (env->fractal == '2')
	{
		env->p_r = (float)(x - WIDTH / 2) / WIDTH * 2;
		env->p_i = (float)(y - HEIGHT / 2) / HEIGHT * 2;
		printf("%f;%f\n", env->p_r, env->p_i);
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
		x -= WIDTH;
		y -= HEIGHT;
		env->zoom = (env->zoom + 1) * 1.1;
		env->start_x += x / env->zoom / 1.5;
		env->start_y += y / env->zoom / 1.5;
	}
	else if (button == 5 && env->zoom > 1)
	{
		printf("zoom [%f]\n", env->zoom);
		env->zoom = (env->zoom - 1) / 1.1;
	}
	redraw(env);
	return (0);
}
