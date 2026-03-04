# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/04 17:21:47 by acasper           #+#    #+#              #
#    Updated: 2026/03/04 17:25:13 by acasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
	  src/prompt.c \
	  src/exec.c \
	  src/utils.c

INC = -Iinclude

all:
	$(CC) $(CFLAGS) $(SRC) $(INC) -lreadline -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

