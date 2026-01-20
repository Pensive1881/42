/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:41:01 by acasper           #+#    #+#             */
/*   Updated: 2026/01/20 14:18:03 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/get_next_line.h"
# include "libft/libft.h"
# include <fcnhtl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define WALL 49 // '1'
# define EMPTY 48 // '0'
# define COLLECTIBLE 67 // 'C'
# define EXIT 69 // 'E'
# define PLAYER 80 // 'P'

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_textures
{
	t_img		wall;
	t_img		floor;
	t_img		collectible;
	t_img		exit;
	t_img		player;
}				t_textures;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles;
	int			exit;
	int			players;
	t_point		player_pos;
	t_point		exit_pos;
}				t_map;

typedef struct s_game
{
	void		*mix;
	void		*win;
	t_map		map;
	t_textures	textures;
	int			moves;
	int			collected;
}				t_game;

// Map Parsing
int				parse_map(char *filename, t_game *game);
int				validate_map(t_game *game);
int				check_path(t_game *game);
void			free_map(char **map);

// Map Validation
int				is_rectangular(char **map);
int				is_surrounded_by_walls(t_map *map);
int				count_map_elements(t_map *map);

// Game Initialization
int				init_game(t_game *game);
int				load_textures(t_game *game);
void			free_textures(t_game *game);

// Game Loop
int				game_loop(t_game *game);
void			render_map(t_game *game);
int				handle_keypress(int keycode, t_game *game);
int				handle_close(t_game *game);

// Player Movement
int				move_player(t_game *game, int new_x, int new_y);
void			update_player_position(t_game *game, int new_x, int new_y);

// Utils
void			error_exit(char *message);
void			cleanup_game(t_game *game);
int				get_map_width(char *line);
int				get_map_height(char *filename);

#endif
