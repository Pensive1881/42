/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:34:22 by acasper           #+#    #+#             */
/*   Updated: 2026/02/26 14:20:42 by acasper          ###   ########.fr       */
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
}

int	load_textures(t_game *game)
{
	if (!load_xpm(game, &game->textures.wall, "textures/wall.xpm"))
		return (0);
	if (!load_xpm(game, &game->textures.floor, "textures/floor.xpm"))
		return (0);
	if (!load_xpm(game, &game->textures.collectible, "textures/coin-bag.xpm"))
		return (0);
	if (!load_xpm(game, &game->textures.exit, "textures/exit-closed.xpm"))
		return (0);
	if (!load_xpm(game, &game->textures.player, "textures/player_front.xpm"))
		return (0);
	return (1);
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
