*This project has been created as part of the 42 curriculum by acasper.*

# Push_swap

## Description

Push_swap is an algorithmic project that sorts a stack of integers using a limited set of operations.
The goal is to sort the numbers in ascending order using the minimum number of moves possible.

The program takes a list of integers as arguments and outputs the sequence of operations needed to sort them. Two stacks (a and b) are used, with stack a initially containing the input and stack b starting empty.

### Available Operations

The following instructions can be used:

- `sa` – swap the first two elements of stack a  
- `sb` – swap the first two elements of stack b  
- `ss` – sa and sb at the same time  
- `pa` – push top element from b to a  
- `pb` – push top element from a to b  
- `ra` – rotate stack a (first element becomes last)  
- `rb` – rotate stack b  
- `rr` – ra and rb at the same time  
- `rra` – reverse rotate stack a  
- `rrb` – reverse rotate stack b  
- `rrr` – rra and rrb at the same time  

## Instructions


### Compilation

Compile the project using the Makefile:

make

Available rules:

make
make clean
make fclean
make re

The project is compiled using the flags:

-Wall -Wextra -Werror

## Resources
https://en.wikipedia.org/wiki/Radix_sort

AI tools were used to:
 - Understand the radix sort algorithm and its application to this problem
 - Organise README.md files

