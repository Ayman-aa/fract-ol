# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 18:21:58 by aaamam            #+#    #+#              #
#    Updated: 2024/01/24 18:36:34 by aaamam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c src/render.c src/mandelbrot.c src/julia.c src/utils.c \
		src/key_event_hook.c
CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = fractol
RM = rm -f
FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(FRAMEWORKS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
