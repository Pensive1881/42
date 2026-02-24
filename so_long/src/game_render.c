/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:16:42 by acasper           #+#    #+#             */
/*   Updated: 2026/02/23 11:51:02 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	render_title(t_game *game, char tile, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.floor.img, x
		* TILE_SIZE, y * TILE_SIZE);
	if (tile == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.player.img,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_title(game, game->map.grid[y][x], x, y);
			x++;
		}
		y++;
	}
}
