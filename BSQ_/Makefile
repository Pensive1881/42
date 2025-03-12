# Compiler and flags for C files
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Perl script file and C program
PERL_SCRIPT = generate_grid.pl
C_PROGRAM = bsq
C_SOURCES = bsq.c get_map.c  # Include C source files
C_HEADERS = bsq.h

# Default values for the grid
X = 10
Y = 10
DENSITY = 2

# Default target to compile the C program
all: $(C_PROGRAM)

# Rule to create the C program from source
$(C_PROGRAM): $(C_SOURCES) $(C_HEADERS)
	$(CC) $(CFLAGS) -o $(C_PROGRAM) $(C_SOURCES)

# General pattern rule to compile any .c file into its respective .o file
# For each .c file in the C_SOURCES list, generate corresponding .o
%.o: %.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# 'run' target to generate the grid file and then run the C program
run: $(C_PROGRAM)
	./$(PERL_SCRIPT) $(X) $(Y) $(DENSITY) > example_file
	./$(C_PROGRAM) example_file

# Clean target to remove generated files
clean:
	rm -f $(C_PROGRAM) example_file

# fclean target to remove all generated files (including the executable and object files)
fclean: clean
	rm -f $(C_SOURCES:.c=.o)

# Rebuild everything (fclean and then all)
re: fclean all

.PHONY: all clean fclean re run %.o
