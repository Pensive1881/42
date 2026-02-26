/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:34:22 by acasper           #+#    #+#             */
/*   Updated: 2026/02/26 12:34:30 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	load_xpm(t_game *game, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx,
			path,
			&img->width,
			&img->height);
	return (img->img != NULL);
/*
	int	x;
	int	y;
	int	pixel;

	img->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!img->img)
		return ;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
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
*/
}

int	load_textures(t_game *game)
{
	if (!load_xpm(game, &game->textures.wall, "assets/wall.xpm"))
		return (0);
	if (!load_xpm(game, &game->textures.floor, "assets/floor.xpm"))
		return (0);
	if (!load_xpm(game, &game->textures.collectible, "assets/coin-bag.xpm"))
		return (0);
	if (!load_xpm(game, &game->textures.exit, "assets/exit-closed.xpm"))
		return (0);
	if (!load_xpm(game, &game->textures.player, "assets/player_front.xpm"))
		return(0);
	return (1);
/*
	create_colored_square(game, &game->textures.wall, 0x808080);
	create_colored_square(game, &game->textures.floor, 0xFFFFFF);
	create_colored_square(game, &game->textures.collectible, 0xFFD700);
	create_colored_square(game, &game->textures.exit, 0x00FF00);
	create_colored_square(game, &game->textures.player, 0x0000FF);
	if (!game->textures.wall.img || !game->textures.floor.img
		|| !game->textures.collectible.img || !game->textures.exit.img
		|| !game->textures.player.img)
		return (0);
*/
}

void	free_textures(t_game *game)
{
	if (game->textures.wall.img)
		mlx_destroy_image(game->mlx, game->textures.wall.img);
	if (game->textures.floor.img)
		mlx_destroy_image(game->mlx, game->textures.floor.img);
	if (game->textures.collectible.img)
		mlx_destroy_image(game->mlx, game->textures.collectible.img);
	if (game->textures.exit.img)
		mlx_destroy_image(game->mlx, game->textures.exit.img);
	if (game->textures.player.img)
		mlx_destroy_image(game->mlx, game->textures.player.img);
}
