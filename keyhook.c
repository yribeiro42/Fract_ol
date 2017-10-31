/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:05:13 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/31 16:20:32 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_env(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_window(e->mlx, e->win);
	free(e);
	exit(0);
}

int		key_press_hook(int key, t_env *e)
{
	if (key == ESC)
		destroy_env(e);
	if (key == RIGHT)
		e->sx += 0.1;
	if (key == LEFT)
		e->sx -= 0.1;
	if (key == UP)
		e->sy -= 0.1;
	if (key == DOWN)
		e->sy += 0.1;
	if (key == PLUS)
		e->iter += 10;
	if (key == MINUS)
		e->iter -= 10;
	if (key == 49 && e->motion)
		e->motion = 0;
	else if (key == 49 && !e->motion)
		e->motion = 1;
	redraw(e);
	return (0);
}
