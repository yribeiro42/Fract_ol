/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:29:09 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/31 16:19:59 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	init_burningship(t_env *e)
{
	e->sx = -0.3;
	e->sy = -0.3;
	e->z = 0.8;
	e->iter = 100;
	e->color = 0xFFAA00;
	e->flag = 1;
}

int		burningship(t_env *e)
{
	t_complex	new;
	t_complex	old;
	int			i;

	new.real = 0;
	new.imag = 0;
	i = 0;
	while ((new.real * new.real + new.imag * new.imag) < 4.0 &&
		i < e->iter)
	{
		old.real = new.real;
		old.imag = new.imag;
		new.real = old.real * old.real - old.imag * old.imag + e->pr;
		new.imag = 2.0 * fabs(old.real * old.imag) + e->pi;
		i++;
	}
	if (i == e->iter)
		return (0);
	return (i);
}

void	draw_burningship(t_env *e)
{
	int	x;
	int	y;
	int color;

	if (!e->flag)
		init_burningship(e);
	y = 0;
	while (y < HEIGHT)
	{
		e->pi = (y - HEIGHT / 2.0) / (0.5 * e->z * HEIGHT) + e->sy;
		x = 0;
		while (x < WIDTH)
		{
			e->pr = 1.5 * (x - WIDTH / 2.0) / (0.5 * e->z * WIDTH) + e->sx;
			color = (e->color * (burningship(e) % 255));
			fill_pixel(e, x, y, color);
			x++;
		}
		y++;
	}
}
