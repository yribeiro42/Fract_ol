/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:20:30 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/20 11:33:57 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	write(1, "Usage: ./fractol #\n 1: Mandelbrot\n"
				" 2: Julia\n 3: Burning Ship\n", 61);
	exit(0);
}

void	fractol(t_env *env)
{
	if (env->fractal == '1')
		draw_mandelbrot(env);
	else if (env->fractal == '2')
		draw_julia(env);
	else
		draw_burningship(env);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2)
		usage();
	if (!(env = ft_memalloc(sizeof(t_env))))
		return (0);
	init_env(env);
	create_env(env);
	if (argv[1][0] == '1' || argv[1][0] == '2' || argv[1][0] == '3')
	{
		env->fractal = argv[1][0];
		fractol(env);
	}
	else
		usage();
	draw_image(env);
	//mlx_do_key_autorepeaton(env->mlx);
	mlx_key_hook(env->win, key_press_hook, env);
	mlx_mouse_hook(env->win, mouse_button_hook, env);
	mlx_hook(env->win, MotionNotify, PointerMotionMask, mouse_motion, env);
	mlx_loop(env->mlx);
	return (0);
}
