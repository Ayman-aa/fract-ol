# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 19:16:39 by aaamam            #+#    #+#              #
#    Updated: 2024/01/24 19:16:40 by aaamam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

NAME_BONUS = fractol_bonus

SRC = mandelbrot.c render.c events.c main.c tools.c julia.c initial.c parcing.c

MLX =  -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

CFLAGS = -Wall -Werror -Wextra -O3

CC = cc

B_C = render_bonus.c events_bonus.c tools_bonus.c init_bonus.c burning_ship.c main_bonus.c

HEADER = fractol.h

%.o : %.c
	cc -c -O3 -o $@ $<

${NAME}: ${SRC} ${HEADER}
		@${CC} ${SRC} ${CFLAGS} -O3 -o ${NAME} $(MLX)
		@echo "Your FrAcToL is reaDy"

${NAME_BONUS}: ${B_C} ${HEADER}
		@${CC} ${CFLAGS} ${B_C} ${MLX} -o ${NAME_BONUS}
		@echo "Your BurNIng ShIp is reaDy"

bonus: ${NAME_BONUS}

clean:
	@rm -rf ${NAME}
	@echo "FrAcToL ReMovEd"

fclean:
	@rm -rf ${NAME} ${NAME_BONUS}
	@echo "All ReMoVed"

all: ${NAME} bonus

re: fclean all
