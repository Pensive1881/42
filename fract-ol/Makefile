# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 20:01:48 by acasper           #+#    #+#              #
#    Updated: 2025/09/11 20:01:53 by acasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = include/libft
MLX_PATH = include/minilibx

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SRC_FILES = 
OBJ_FILES = 

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)


clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

