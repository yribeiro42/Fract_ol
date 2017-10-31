/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:29:09 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/31 16:20:03 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_pixel(t_env *e, int x, int y, int hexcolor)
{
	int pos;

	pos = (4 * x) + (4 * y * WIDTH);
	e->img_str[pos] = hexcolor;
	e->img_str[pos + 1] = hexcolor >> 8;
	e->img_str[pos + 2] = hexcolor >> 16;
}

void	redraw(t_env *e)
{
	int bpp;
	int size_line;
	int endian;

	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img_str = mlx_get_data_addr(e->img_ptr, &bpp, &size_line, &endian);
	fractol(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	create_ui(e);
	mlx_destroy_image(e->mlx, e->img_ptr);
}
