# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 14:34:35 by aaamam            #+#    #+#              #
#    Updated: 2024/01/25 13:13:24 by aaamam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

NAME_BONUS = fractol_bonus

SRC = mandelbrot.c render.c events.c main.c tools.c julia.c initial.c parcing.c

MLX =  -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

CFLAGS = -Wall -Werror -Wextra

CC = cc

B_C = render_bonus.c events_bonus.c tools_bonus.c init_bonus.c burning_ship.c main_bonus.c

HEADER = fractol.h

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${SRC} ${HEADER}
		@${CC} ${SRC} ${CFLAGS} -o ${NAME} $(MLX)
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
