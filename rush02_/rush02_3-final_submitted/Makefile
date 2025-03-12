# Variables
CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=rush-02 #name of the executable file that will be generated
SRC=main_read_file.c  

# Rules
all: $(NAME)

$(NAME): $(SRC) 
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) 

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all