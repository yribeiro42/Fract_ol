/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:51:21 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/19 13:42:42 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_env *env)
{
	env->start_x = -0.5;
	env->start_y = 0.0;
	env->zoom = 1.0;
	env->iteration = 100;
	env->color = 0x070BFF;
	env->flag = 1;
}

int		mandelbrot(t_env *env)
{
	t_complex	new;
	t_complex	old;
	int			i;

	new.imag = 0;
	new.real = 0;
	i = 0;
	while ((new.real * new.real + new.imag * new.imag) < 4.0 && i < env->iteration)
	{
		old.real = new.real;
		old.imag = new.imag;
		new.real = (old.real * old.real) - (old.imag * old.imag) + env->p_r;
		new.imag = 2 * old.real * old.imag + env->p_i;
		i++;
	}
	if (i == env->iteration)
	{
		return (0);
	}
	return (i);
}

void	draw_mandelbrot(t_env *env)
{
	int	x;
	int	y;
	int color;

	if (!env->flag)
		init_mandelbrot(env);
	y = 0;
	while (y < HEIGHT)
	{
		env->p_i = (y - HEIGHT / 2.0) / (0.5 * env->zoom * HEIGHT) + env->start_y;
		x = 0;
		while (x < WIDTH)
		{
			env->p_r = 1.5 * (x - WIDTH / 2.0) / (0.5 * env->zoom * WIDTH) + env->start_x;
			color = (env->color * (mandelbrot(env) % 255));
			fill_pixel(env, x, y, color);
			x++;
		}
		y++;
	}
}
