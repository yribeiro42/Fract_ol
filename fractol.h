/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:28:08 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/31 16:15:55 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "X.h"

# define WIDTH 500
# define HEIGHT 500
# define ESC 53
# define PAGE_UP 116
# define PAGE_DOWN 121
# define PLUS 24
# define MINUS 27
# define LEFT 123
# define UP 126
# define RIGHT 124
# define DOWN 125

typedef	struct	s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct	s_env
{
	void		*mlx;
	void		*mlx2;
	void		*win;
	void		*win2;
	char		*img_str;
	void		*img_ptr;
	char		fractal;
	int			iter;
	int			color;
	int			flag;
	int			debug;
	int			motion;
	int			hud;
	double		z;
	double		sx;
	double		sy;
	double		pi;
	double		pr;
	t_complex	c;
}				t_env;

void			fill_pixel(t_env *env, int x, int y, int hexcolor);
void			draw(t_env *env);

void			init_mandelbrot(t_env *env);
int				mandelbrot(t_env *env);
void			draw_mandelbrot(t_env *env);

void			init_julia(t_env *env);
int				julia(t_env *env, int x, int y);
void			draw_julia(t_env *env);

void			init_burningship(t_env *env);
int				burningship(t_env *env);
void			draw_burningship(t_env *env);

void			init_env(t_env *env);
void			create_env(t_env *env);
void			draw_image(t_env *env);
void			fractol(t_env *env);
void			redraw(t_env *env);

int				key_press_hook(int key, t_env *env);
int				mouse_button_hook(int button, int x, int y, t_env *env);
int				mouse_motion(int x, int y, t_env *env);
void			set_hooks(t_env *env);

void			create_ui(t_env *env);

#endif
