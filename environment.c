/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:29:09 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/31 16:22:25 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fractol");
}

void	create_env(t_env *e)
{
	int bpp;
	int size_line;
	int endian;

	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img_str = mlx_get_data_addr(e->img_ptr, &bpp, &size_line, &endian);
}

void	draw_image(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	create_ui(e);
	mlx_destroy_image(e->mlx, e->img_ptr);
}

void	set_hooks(t_env *e)
{
	mlx_hook(e->win, 2, 0, key_press_hook, e);
	mlx_hook(e->win, 4, 0, mouse_button_hook, e);
}

void	create_ui(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0xC0C0C0, "Iter : + -");
	mlx_string_put(e->mlx, e->win, 10, 30, 0xC0C0C0, "Move : arrows");
	mlx_string_put(e->mlx, e->win, 10, 50, 0xC0C0C0, "Zoom : mouse button");
}
