/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:17:21 by yoann             #+#    #+#             */
/*   Updated: 2017/10/31 16:20:26 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_env *e)
{
	e->sx = 0.0;
	e->sy = 0.0;
	e->z = 1;
	e->iter = 25;
	e->color = 0x070BFF;
	e->pr = -0.7;
	e->pi = 0.27;
	e->flag = 1;
	e->motion = 1;
}

int		julia(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	int			i;

	i = 0;
	new.imag = (y - HEIGHT / 2.0) / (0.5 * e->z * HEIGHT) + e->sy;
	new.real = 1.5 * (x - WIDTH / 2.0) / (0.5 * e->z * WIDTH) + e->sx;
	while ((new.real * new.real + new.imag * new.imag) < 4.0 && i < e->iter)
	{
		old.real = new.real;
		old.imag = new.imag;
		new.real = old.real * old.real - old.imag * old.imag + e->pr;
		new.imag = 2.0 * old.real * old.imag + e->pi;
		i++;
	}
	if (i == e->iter)
		return (0);
	return (i);
}

void	draw_julia(t_env *e)
{
	int	x;
	int	y;
	int color;

	if (!e->flag)
		init_julia(e);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = (e->color * (julia(e, x, y) % 255));
			fill_pixel(e, x, y, color);
			x++;
		}
		y++;
	}
}
