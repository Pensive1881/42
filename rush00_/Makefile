# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files (located inside ex00/)
SRC = ex00/main.c ex00/ft_putchar.c ex00/rush04.c

# Object files (store them in ex00/)
OBJ = $(SRC:.c=.o)

# Executable name
NAME = ex00/rush

# Default target
all: $(NAME)

# Compile and link the program
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compile .c files into .o files inside ex00/
ex00/%.o: ex00/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files and executable
fclean: clean
	rm -f $(NAME)

# Recompile from scratch
re: fclean all

