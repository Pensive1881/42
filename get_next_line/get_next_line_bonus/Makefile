# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 22:05:30 by acasper           #+#    #+#              #
#    Updated: 2025/06/17 21:58:14 by acasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

BUFFER_SIZE ?= 42
CPPFLAGS = -D BUFFER_SIZE=$(BUFFER_SIZE)

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c 
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus:
	$(CC) $(CFFLAGS) $(CPPFLAGS) -c $(BONUS_SRCS)
	ar rcs $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
