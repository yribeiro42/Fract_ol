/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:51:21 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/31 16:19:27 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_env *e)
{
	e->sx = -1.5;
	e->sy = 0.0;
	e->z = 2.5;
	e->iter = 30;
	e->color = 0x070BFF;
	e->flag = 1;
}

int		mandelbrot(t_env *e)
{
	t_complex	new;
	t_complex	old;
	int			i;

	new.imag = 0;
	new.real = 0;
	i = 0;
	while ((new.real * new.real + new.imag * new.imag) < 4.0 && i < e->iter)
	{
		old.real = new.real;
		old.imag = new.imag;
		new.real = (old.real * old.real) - (old.imag * old.imag) + e->pr;
		new.imag = 2 * old.real * old.imag + e->pi;
		i++;
	}
	if (i == e->iter)
	{
		return (0);
	}
	return (i);
}

void	draw_mandelbrot(t_env *e)
{
	int	x;
	int	y;
	int color;

	if (!e->flag)
		init_mandelbrot(e);
	y = 0;
	while (y < HEIGHT)
	{
		e->pi = (y - HEIGHT / 2.0) / (0.5 * e->z * HEIGHT) + e->sy;
		x = 0;
		while (x < WIDTH)
		{
			e->pr = 1.5 * (x - WIDTH / 2.0) / (0.5 * e->z * WIDTH) + e->sx;
			color = (e->color * (mandelbrot(e) % 255));
			fill_pixel(e, x, y, color);
			x++;
		}
		y++;
	}
}
