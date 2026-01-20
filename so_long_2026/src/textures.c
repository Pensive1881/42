/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:34:22 by acasper           #+#    #+#             */
/*   Updated: 2026/01/20 18:22:54 by acasper          ###   ########.fr       */
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
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			pixel = y * img->line_length + x * (img->bits_per_pixel / 8);
			*(unsigned int *)(img->addr + pixel) = color;
			x++;
		}
		y++;
	}
}

int	load_textures(t_game *game)
{
	create_colored_square();
	create_colored_square();
	create_colored_square();
	create_colored_square();
	create_colored_square();
	if ()
	{
		
	}
	
}

void	free_textures(t_game *game)
{
	
}
