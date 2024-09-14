# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 15:03:55 by hdelbecq          #+#    #+#              #
#    Updated: 2024/09/14 17:36:47 by hdelbecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC =	src/clean.c src/init.c src/main.c src/render.c src/map.c src/hook.c src/check_map.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		utils/ft_strlen.c utils/ft_free.c utils/ft_strchr.c
OBJ = $(SRC:.c=.o)
MLX = minilibx-linux/libmlx.a

all: $(NAME)
 
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
