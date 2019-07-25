# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 19:10:46 by slaanani          #+#    #+#              #
#    Updated: 2019/05/08 23:58:41 by slaanani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS1 = -I ./includes -I /usr/local/include -Wall -Werror -Wextra
CFLAGS2 = -I ./includes -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRC1		= 	mandelbrot.c\
				julia.c\
				burning_ship.c\
				coloring.c\
				key_hooking.c\
				user_interface.c\
				cubic_mandelbrot.c\
				fourth_mandelbrot.c\
				assign_limits.c\
				parse_fractal.c\
				fractals.c\
				mouse_hooking.c
SRC2 = fractol.c

SRC1 := $(addprefix srcs/, $(SRC1))
SRC2 := $(addprefix srcs/, $(SRC2))

.PHONY: all

all: $(NAME)

$(NAME):
		@make -C srcs/libft
		@gcc $(CFLAGS1) -c $(SRC1)
		@gcc srcs/libft/*.o *.o $(SRC2) $(CFLAGS2) -o $(NAME)
		@mkdir bins
		@mkdir bins/objs
		@mv srcs/libft/*.o *.o bins/objs
		@echo "\x1b[32m---------- COMPILED SUCCESSFULLY ----------\x1b[0m"


.PHONY: clean
clean:
	@rm -rf bins/objs
	@rm -f *.o
	@echo "\x1b[32m---------- CLEANED SUCCESSFULLY ----------\x1b[0m"

.PHONY: fclean

fclean: clean
	@rm -rf bins
	@rm -f $(NAME)

re: fclean all
