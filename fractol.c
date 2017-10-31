/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:20:30 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/31 16:21:53 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	write(1, "Usage: ./fractol #\n 1: Mandelbrot\n"
				" 2: Julia\n 3: Burning Ship\n", 61);
	exit(0);
}

void	fractol(t_env *e)
{
	if (e->fractal == '1')
		draw_mandelbrot(e);
	else if (e->fractal == '2')
		draw_julia(e);
	else
		draw_burningship(e);
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2)
		usage();
	if (!(e = ft_memalloc(sizeof(t_env))))
		return (0);
	init_env(e);
	create_env(e);
	if (argv[1][0] == '1' || argv[1][0] == '2' || argv[1][0] == '3')
	{
		e->fractal = argv[1][0];
		fractol(e);
	}
	else
		usage();
	draw_image(e);
	mlx_key_hook(e->win, key_press_hook, e);
	mlx_mouse_hook(e->win, mouse_button_hook, e);
	mlx_hook(e->win, MotionNotify, PointerMotionMask, mouse_motion, e);
	mlx_loop(e->mlx);
	return (0);
}
