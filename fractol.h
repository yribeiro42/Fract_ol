#include <stdio.h>
#include "libft/libft.h"
#include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 600

#define ESC 65307
#define PAGE_UP 65365
#define PAGE_DOWN 65366
#define PLUS 61
#define MINUS 45
#define UP 65362
#define RIGHT 65363
#define BOTTOM 65364
#define LEFT 65361

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
	double		zoom;	
	double		start_x;
	double		start_y;
	double		p_i;
	double		p_r;
	int			(*fractal_ptr)(struct s_env*);
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
int		julia(t_env *env);
void	draw_julia(t_env *env);

// BURNINGSHIP //

void	init_burningship(t_env *env);
int		burningship(t_env *env);
void	draw_burningship(t_env *env);

// ENV //

void	init_env(t_env *env);
void	create_env(t_env *env);
void	destroy_env(t_env *env);

// HOOK //

int		key_hook(int key, t_env *env);
