/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:41:01 by acasper           #+#    #+#             */
/*   Updated: 2026/01/19 17:45:16 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "../src/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcnhtl.h>
# include <math.h>

# define TILE_SIZE 32
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct	s_point
{
	int	x;
	int	y;	
}	t_point;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	width;
	int	height;
}	t_img;

typedef struct	s_textures
{
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	exit;
	t_img	player;
}	t_textures;

typedef struct	s_map
{
	char	**grid;
	int	width;
	int	height;
	int	collectibles;
	int	exit;
	int	players;
	t_point	player_pos;
	t_point	exit_pos;
}	t_map;

typedef struct	s_game
{
	void	*mix;
	void	*win;
	t_map	map;
	t_textures	textures;
	int	moves;
	int	collected;
}	t_game;

// Map Parsing
int	parse_map();
int	validate_map();
int	check_path();
void	free_map();

// Map Validation
int	is_rectangular();
int	is_surrounded_by_walls();
int	count_map_elements();

// Game Initialization
int	init_game();
int	load_textures();
void	free_textures();

// Game Loop
int	game_loop();
void	render_map();
int	handle_keypress();
int	handle_close();

// Player Movement
int	move_player();
void	update_player_position();

// Utils
void	error_exit();
void	cleanup_game();
int	get_map_width();
int	get_map_height();

#endif
