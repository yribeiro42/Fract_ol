# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoann <yoann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/13 16:14:59 by yribeiro          #+#    #+#              #
#    Updated: 2017/10/30 19:28:32 by yoann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror
SRC = fractol.c draw.c environment.c mandelbrot.c keyhook.c julia.c burningship.c mouse_hook.c
OBJ = $(SRC:.c=.o)
LIBFT_H = -Ilibft/
LIBFT = libft/libft.a
MLX = -L /usr/local/lib -lmlx -lXext -lX11 -lm
MACMLX = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o : %.c
	gcc $(CFLAGS) $(LIBFT_H) -c $?

$(NAME): $(OBJ)
	make -C libft/
	#gcc $(CFLAGS) -o $(NAME) $^ -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	gcc $(CFLAGS) -o $(NAME) $^ -L /usr/local/lib -lmlx -lXext -lX11 -lm libft.a
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
