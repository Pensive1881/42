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
	  src/utils.c \
	  src/lexer/lex.c \
	  src/lexer/lexer_token.c \
	  src/lexer/lex.utils.c \
	  src/parser/parse.c \
	  src/parser/parse_pipeline.c \
	  src/parser/parse_command.c \
	  src/parser/cmd_utils.c \
	  src/parser/free_parser.c \
	  src/parser/parse_redirection.c \
	  src/arena.c

INC = -Iincludes

all:
	$(CC) $(CFLAGS) $(SRC) $(INC) -lreadline -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

