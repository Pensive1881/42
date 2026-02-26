*This project has been created as part of the 42 curriculum by acasper.*

## Description

so_long is a small 2D game developed using the MiniLibX graphics library.
The objective of the game is simple: the player must collect all collectibles on the map and then reach the exit.

The game validates the map before launching:

The map must be rectangular.

The map must be enclosed by walls.

It must contain exactly one player (P), exactly one exit (E), and at least one collectible (C).

A valid path must exist to collect all collectibles and reach the exit.

The player moves in four directions and each movement is counted and displayed in the terminal.

This project focuses on:

File parsing and validation

Basic game loop architecture

Pathfinding validation (flood fill)

Memory management

Event handling with MiniLibX

## Instructions

### How to Compile

make

This will generate the executable:

./so_long

If you want to recompile:

make re

To clean object files:

make clean

To remove objects and executable:

make fclean

### How to Run
./so_long maps/example.ber

The program requires exactly one argument: a valid .ber map file.

### Controls

W — Move up

A — Move left

S — Move down

D — Move right

ESC — Quit the game

Window close button — Quit the game

Each valid movement increases the move counter, which is printed in the terminal.

### Map Format

The map must use the following characters:

Character	Meaning
0	Empty space
1	Wall
C	Collectible
E	Exit
P	Player starting position

Example:

111111
1P0C01
100001
1C0E01
111111

The map must:

Be rectangular

Be surrounded by walls

Contain exactly 1 P

Contain exactly 1 E

Contain at least 1 C

Have a valid path to collect all collectibles and reach the exit

### Project Structure
src/        → Source files
maps/       → Map files (.ber)
textures/   → Textures (XPM images)
libft/      → Custom C library

## Resources

42 MiniLibX documentation

42 subject PDF for so_long

Manual pages (man mlx, man open, etc.)

Personal testing using valgrind for memory leak detection

AI assistance was used for:
Verifying edge cases
Improving documentation clarity

