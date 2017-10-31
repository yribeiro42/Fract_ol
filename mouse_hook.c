/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:30:15 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/31 16:23:22 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_env *e, int x, int y, double factor)
{
	double scale;
	double diff;
	double offsetx;
	double offsety;

	scale = e->z * factor;
	diff = scale - e->z;
	offsetx = (((double)((HEIGHT / 2) - x) / HEIGHT) * diff);
	offsety = (((double)((HEIGHT / 2) - y) / HEIGHT) * diff);
	e->sx -= offsetx;
	e->sy -= offsety;
	e->z = scale;
}

void	zoom_out(t_env *e, int x, int y, double factor)
{
	double scale;
	double diff;
	double offsetx;
	double offsety;

	scale = e->z * factor;
	diff = scale - e->z;
	offsetx = (((double)((HEIGHT / 2) - x) / HEIGHT) * diff);
	offsety = (((double)((HEIGHT / 2) - y) / HEIGHT) * diff);
	e->sx += offsetx;
	e->sy += offsety;
	e->z = scale;
}

int		mouse_motion(int x, int y, t_env *e)
{
	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return (0);
	if (e->fractal == '2' && e->motion)
	{
		e->pr = (float)(x - WIDTH / 2) / WIDTH * 2;
		e->pi = (float)(y - HEIGHT / 2) / HEIGHT * 2;
		redraw(e);
	}
	return (0);
}

int		mouse_button_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
		e->z += 0.5;
	else if (button == 2)
		e->z -= 0.5;
	if (button == 4)
		zoom_in(e, x, y, 1.025);
	else if (button == 5 && e->z > 0.7)
		zoom_out(e, x, y, 0.985);
	redraw(e);
	return (0);
}
