/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:30:15 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/19 19:27:38 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		 x -= WIDTH;
		 y -= HEIGHT;
		 env->zoom = (env->zoom + 1) * 1.1;
		 printf("zoom = %f\n", env->zoom);

		 
		 env->start_y += y / env->zoom / 1.5;
		 //printf("start y %f\n", env->start_y);
		 env->start_x += x / env->zoom / 1.5;
		 printf("start x %f\n", env->start_x);
	}
	else if (button == 5 && env->zoom > 1)
	{
		printf("zoom [%f]\n", env->zoom);
		env->zoom = (env->zoom - 1) / 1.1;
	}
	redraw(env);
	return (0);
}
