# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 18:59:25 by acasper           #+#    #+#              #
#    Updated: 2025/09/25 20:17:37 by acasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCS = -I ./libft

SERVER = server
CLIENT = client
NAME = $(SERVER) $(CLIENT)

SRCS_SERVER = server.c $(SRCS_COMMON)
SRCS_CLIENT = client.c $(SRCS_COMMON)

OBJS_SERVER =	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT =	$(SRCS_CLIENT:.c=.o)

LIBFT_DIR = ./libft
LIBFT	= $(LIBFT_DIR)/libft.a

all: $(SERVER) $(CLIENT)
$(NAME): all

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(INCS) $(OBJS_SERVER) $(LIBFT) -o $@

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(INCS) $(OBJS_CLIENT) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	@-$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	@-$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

