/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:29:09 by yribeiro          #+#    #+#             */
/*   Updated: 2017/06/13 17:36:19 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	init_burningship(t_env *env)
{
	env->start_x = -0.3;
	env->start_y = 0.0;
	env->zoom = 0.1;
	env->iteration = 100;
	env->color = 0xFFAA00;
	env->flag = 1;
}

int		burningship(t_env *env)
{
	t_complex	new;
	t_complex	old;
	int			i;
	
	new.real = 0;
	new.imag = 0;
	i = 0;
	while ((new.real * new.real + new.imag * new.imag) < 4.0 && i < env->iteration)
	{
		old.real = new.real;
		old.imag = new.imag;
		new.real = old.real * old.real - old.imag * old.imag + env->p_r;
		new.imag = 2.0 * fabs(old.real * old.imag) + env->p_i;
		i++;
	}
	if (i == env->iteration)
		return (0);
	return (i);
}

void	draw_burningship(t_env *env)
{
	if (!env->flag)
		init_burningship(env);
	int	x;
	int	y;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		env->p_i = (y - HEIGHT / 2.0) / (0.5 * env->zoom * HEIGHT) + env->start_y;
		x = 0;
		while (x < WIDTH)
		{
			env->p_r = 1.5 * (x - WIDTH / 2.0) / (0.5 * env->zoom * WIDTH) + env->start_x;
			color = (env->color * (burningship(env) % 255));
			fill_pixel(env, x, y, color);
			x++;
		}
		y++;
	}
}
