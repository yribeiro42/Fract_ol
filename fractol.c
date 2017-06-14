/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:20:30 by yribeiro          #+#    #+#             */
/*   Updated: 2017/06/14 18:02:54 by yoann            ###   ########.fr       */
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
	env = malloc(sizeof(t_env));
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
	mlx_do_key_autorepeaton(env->mlx);
	mlx_key_hook(env->win, key_press_hook, env);
	mlx_mouse_hook(env->win, mouse_button_hook, env);
	mlx_hook(env->win, MotionNotify, PointerMotionMask, mouse_motion, env);
	mlx_loop(env->mlx);
	return (0);
}
