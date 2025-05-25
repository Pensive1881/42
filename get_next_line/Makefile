# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 22:05:30 by acasper           #+#    #+#              #
#    Updated: 2025/05/25 22:07:58 by acasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
        $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
        rm -f $(OBJS)

fclean: clean
        rm -f $(NAME)

re: fclean all
