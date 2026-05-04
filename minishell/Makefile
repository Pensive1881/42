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
SRCDIR = src
HEADERDIR = includes
LIBFTDIR = libft
BUILDDIR = build

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I$(HEADERDIR) -I$(LIBFTDIR)/includes
LIBFT = $(LIBFTDIR)/libft.a

SRC = src/main.c \
	  src/prompt.c \
	  src/exec.c \
	  src/signals.c \
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
	  src/parser/syntax_check.c \
	  src/arena.c \
	  src/exec/execute_pipeline.c \
	  src/exec/execute_single.c \
	  src/exec/execute_multi.c \
	  src/exec/path.c \
	  src/exec/redirections.c \
	  src/exec/exec_utils.c \
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

$(NAME): $(OBJFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBFT) -lreadline -o $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	make -C $(LIBFTDIR) clean
	rm -rf $(BUILDDIR)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: clean all
