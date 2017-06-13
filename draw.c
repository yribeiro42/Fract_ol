/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:29:09 by yribeiro          #+#    #+#             */
/*   Updated: 2017/06/13 18:01:44 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_pixel(t_env *env, int x, int y, int hexcolor)
{
	int pos;

	pos = (4 * x) + (4 * y * WIDTH);
	env->img_str[pos] = hexcolor;
	env->img_str[pos + 1] = hexcolor >> 8;
	env->img_str[pos + 2] = hexcolor >> 16;
}

void	redraw(t_env *env)
{
	int bpp;
	int size_line;
	int endian;

	env->img_ptr = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_str = mlx_get_data_addr(env->img_ptr, &bpp, &size_line, &endian);
	fractol(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img_ptr, 0, 0);
	mlx_destroy_image(env->mlx, env->img_ptr);
}
