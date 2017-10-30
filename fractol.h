/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:28:08 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/30 15:19:03 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
//#include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Tk.framework/Versions/8.4/Headers/X11/X.h"
//# include <X11/Xlib.h>

# define WIDTH 400
# define HEIGHT 400
# define WINX WIDTH / (3.0 / 4.0)
# define MOUSEX (env->start_x - WIDTH / 2)
# define MOUSEY (env->start_y - HEIGHT / 2)

# define ESC 53
# define PAGE_UP 116
# define PAGE_DOWN 121

//#define ESC 65307
//#define PAGE_UP 65365
//#define PAGE_DOWN 65366
# define PLUS 61
# define MINUS 45

typedef	struct	s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct 	s_env
{
	void		*mlx;
	void		*win;
	char		*img_str;
	void		*img_ptr;
	char		fractal;
	int			iteration;
	int			color;
	int			flag;
	int			debug;
	int			motion;
	double		zoom;	
	double		start_x;
	double		start_y;
	double		p_i;
	double		p_r;
	t_complex	z;
}				t_env;

// DRAW //

void	fill_pixel(t_env *env, int x, int y, int hexcolor);
void	draw(t_env *env);

// MANDEL //

void	init_mandelbrot(t_env *env);
int		mandelbrot(t_env *env);
void	draw_mandelbrot(t_env *env);

// JULIA //

void	init_julia(t_env *env);
int		julia(t_env *env, int x, int y);
void	draw_julia(t_env *env);

// BURNINGSHIP //

void	init_burningship(t_env *env);
int		burningship(t_env *env);
void	draw_burningship(t_env *env);

// ENV //

void	init_env(t_env *env);
void	create_env(t_env *env);
void	draw_image(t_env *env);
void	fractol(t_env *env);
void	redraw(t_env *env);

// HOOK //

int		key_press_hook(int key, t_env *env);
int		mouse_button_hook(int button, int x, int y, t_env *env);
int		mouse_motion(int x, int y, t_env *env);
void	set_hooks(t_env *env);
