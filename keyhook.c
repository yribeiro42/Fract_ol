/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:05:13 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/30 16:03:03 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_hook(int key, t_env *env)
{
	if (key == ESC)
	{
		free(env);
		exit(0);
	}
	if (key == RIGHT)
		env->start_x /= 1.05;
	if (key == LEFT)
		env->start_x *= 1.05;
	if (key == UP)
		env->start_y -= 0.1;
	if (key == DOWN)
		env->start_y += 0.1;
	if (key == 49 && env->motion)
		env->motion = 0;
	if (key == PLUS)
		env->iteration += 10;
	if (key == MINUS)
		env->iteration -= 10;
	else if (key == 49 && !env->motion)
		env->motion = 1;
	redraw(env);
	return (0);
}
