/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:34:22 by acasper           #+#    #+#             */
/*   Updated: 2026/01/20 18:02:53 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	create_colored_square(t_game *game, t_img *img, int color)
{
	int	x;
	int	y;
	int	pixel;

	img->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!img->img)
		return ;
	img->addr = 
}

int	load_textures(t_game *game)
{
	
}

void	free_textures(t_game *game)
{
	
}
