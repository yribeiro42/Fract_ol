/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:05:13 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/19 17:29:00 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_hook(int key, t_env *env)
{
	//printf("%d\n", key);
	if (key == ESC)
	{
		free(env);
		exit(0);
	}
	if (key == 24)
	{
		// x -= WIDTH;
		// y -= HEIGHT;
		// env->zoom = (env->zoom + 1) * 1.1;

		// printf("start x %f\n", env->start_x);
		
		// env->start_y += y / env->zoom / 1.5;
		// env->start_x += x / env->zoom / 1.5;
	}
	if (key == 27)
	{
		env->zoom = (env->zoom - 1) / 1.1;
	}
	redraw(env);
	return (0);
}
