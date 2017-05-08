#include <stdio.h>
#include "libft/libft.h"
#include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

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
	double		x1;
	double		x2;
	double		y1;
	double		y2;


}				t_env;