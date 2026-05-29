# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/04 17:21:47 by acasper           #+#    #+#              #
#    Updated: 2026/05/29 15:36:55 by acasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCDIR = src
HEADERDIR = includes
LIBFTDIR = libft
BUILDDIR = build
UNAME_S = $(shell uname -s)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I$(HEADERDIR) -I$(LIBFTDIR)/includes
LIBFT = $(LIBFTDIR)/libft.a

ifeq ($(UNAME_S), Darwin)
	READLINE_FLAGS = -lreadline
else
	READLINE_FLAGS = -lreadline -lncurses
endif

SRC = src/main.c \
	  src/prompt.c \
	  src/exec.c \
	  src/signals.c \
	  src/utils.c \
	  src/lexer/lex.c \
	  src/lexer/lexer_token.c \
	  src/lexer/lexer_token_utils.c \
	  src/expansion/expand.c \
	  src/parser/parse.c \
	  src/parser/parse_pipeline.c \
	  src/parser/parse_command.c \
	  src/parser/cmd_utils.c \
	  src/parser/free_parser.c \
	  src/parser/parse_redirection.c \
	  src/parser/syntax_check.c \
	  src/exec/execute_pipeline.c \
	  src/exec/execute_single.c \
	  src/exec/execute_single_utils.c \
	  src/exec/execute_multi.c \
	  src/exec/execute_multi_utils.c \
	  src/exec/path.c \
	  src/exec/redirections.c \
	  src/exec/exec_utils.c \
	  src/exec/child_exec_utils.c \
	  src/exec/heredoc.c \
	  src/buildins/env_utils.c \
	  src/buildins/ft_echo.c \
	  src/buildins/ft_pwd.c \
	  src/buildins/ft_env.c \
	  src/buildins/ft_cd.c \
	  src/buildins/ft_export.c \
	  src/buildins/ft_unset.c \
	  src/buildins/ft_exit.c

OBJFILES = $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	make -C $(LIBFTDIR) clean
	rm -rf $(BUILDDIR)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=ignore_readline_errors.supp ./$(NAME)

re: fclean all

.PHONY: all clean fclean re
