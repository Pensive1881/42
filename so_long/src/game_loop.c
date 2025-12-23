/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:58:00 by acasper           #+#    #+#             */
/*   Updated: 2025/12/23 22:22:40 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_close(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_pos.x;
	new_y = game->map.player_pos.y;
	if (keycode == ESC_KEY)
		handle_close(game);
	else if (keycode == W_KEY || keycode == 119)
		new_y--;
	else if (keycode == S_KEY || keycode == 115)
		new_y++;
	else if (keycode == A_KEY || keycode == 97)
		new_x--;
	else if (keycode == D_KEY || keycode == 100)
		new_x++;
	if (new_x != game->map.player_pos.x || new_y != game->map.player_pos.y)
		move_player(game, new_x, new_y);
	return (0);
}

int	game_loop(t_game *game)
{
	render_map(game);
	mlx_loop(game->mlx);
	return (0);
}
