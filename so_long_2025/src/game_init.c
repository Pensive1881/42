/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:58:00 by acasper           #+#    #+#             */
/*   Updated: 2025/12/23 22:20:03 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx,
			game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE,
			"so_long");
	if (!game->win)
		return (0);
	return (1);
}

static int	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	return (1);
}

int	init_game(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	if (!init_mlx(game))
		return (0);
	if (!load_textures(game))
		return (0);
	if (!setup_hooks(game))
		return (0);
	return (1);
}
