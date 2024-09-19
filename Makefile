# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 15:03:55 by hdelbecq          #+#    #+#              #
#    Updated: 2024/09/19 12:18:15 by hdelbecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC =	src/clean.c src/init.c src/main.c src/render.c src/sprite.c src/hook.c src/check_map.c src/player.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		utils/ft_strlen.c utils/ft_free.c utils/ft_strchr.c utils/ft_strdup.c utils/ft_dup_tab.c
OBJ = $(SRC:.c=.o)
MLX_DIR = mlx_linux
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX = minilibx-linux/libmlx.a

	
all: $(NAME)
	

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C $(MLX_DIR)

re: fclean all
