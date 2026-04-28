NAME = lexer_test

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../../libft/includes -I../../includes -I.

LIBFT = ../../libft/libft.a

SRC = lex.c lex.utils.c lexer_main.c lexer_token.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C ../../libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all