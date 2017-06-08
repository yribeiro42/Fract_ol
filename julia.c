/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:17:21 by yoann             #+#    #+#             */
/*   Updated: 2017/06/08 18:31:26 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	init_julia(t_env *env)
{
	env->start_x = 0.0;
	env->start_y = 0.0;
	env->zoom = 1.0;
	env->iteration = 300;
	env->color = 0x7F15D5;
	env->p_r = -0.7;
	env->p_i = 0.27015;
}

int		julia(t_env *env, int x, int y)
{
	t_complex	new;
	t_complex	old;
	int			i;

	i = 0;
	new.imag = (y - HEIGHT / 2.0) / (0.5 * env->zoom * HEIGHT) + env->start_y;
	new.real = 1.5 * (x - WIDTH / 2.0) / (0.5 * env->zoom * WIDTH) + env->start_x;
	while ((new.real * new.real + new.imag * new.imag) < 4.0 && i < env->iteration)
	{
		old.real = new.real;
		old.imag = new.imag;
		new.real = old.real * old.real - old.imag * old.imag + env->p_r;
		new.imag = 2.0 * old.real * old.imag + env->p_i;
		i++;
	}
	if (i == env->iteration)
		return (0);
	return (i);
}

void	draw_julia(t_env *env)
{
	init_julia(env);
	int	x;
	int	y;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = (env->color * (julia(env, x, y) % 255));
			fill_pixel(env, x, y, color);
			x++;
		}
		y++;
	}
}