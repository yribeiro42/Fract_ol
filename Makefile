NAME = Fract_ol
#CFLAGS = -Wall -Wextra -Werror
SRC = fractol.c draw.c environment.c mandelbrot.c keyhook.c julia.c
OBJ = $(SRC:.c=.o)
LIBFT_H = -Ilibft/
LIBFT = libft/libft.a
MLX = -L /usr/local/lib -lmlx -lXext -lX11 -lm
MACMLX = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(CFLAGS) $(LIBFT_H) -c $(SRC)
	#gcc $(CFLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
