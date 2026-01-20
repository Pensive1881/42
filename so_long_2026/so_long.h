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
	
}	t_point;

typedef struct	s_img
{
	
}	t_imgl;

typedef struct	s_textures
{
	
}	t_textures;

typedef struct	s_map
{
	
}	t_map;

typedef struct	s_game
{
	
}	t_game;

// Map Parsing


// Map Vaslidation


// Game Initialization


// Game Loop


// Player Movement


// Utils


#endif
