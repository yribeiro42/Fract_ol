#include <stdio.h>
#include "libft/libft.h"
#include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000

typedef	struct	s_complex
{
	float		real;
	float		imag;
}				t_complex;

typedef struct 	s_env
{
	void		*mlx;
	void		*win;
	char		*img_str;
	void		*img_ptr;
	t_complex	z;
	t_complex	c;
	int			iteration;
	double		zoom;	
	double		start_x;
	double		start_y;
	double		new_r;
	double		new_i;
	double		old_r;
	double		old_i;
	double		p_i;
	double		p_r;

}				t_env;

// DRAW //

void	fill_pixel(t_env *env, int x, int y, int hexcolor);
void	draw(t_env *env);

// MANDEL //

void	init_mandelbrot(t_env *env);
int		mandelbrot(t_env *env);

// ENV //

void	init_env(t_env *env);
void	create_env(t_env *env);
void	destroy_env(t_env *env);

