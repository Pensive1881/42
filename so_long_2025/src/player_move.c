/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:58:00 by acasper           #+#    #+#             */
/*   Updated: 2025/12/23 22:23:52 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_win_condition(t_game *game)
{
	if (game->collected == game->map.collectibles)
	{
		ft_putendl_fd("Congratulations! You won!", 1);
		handle_close(game);
	}
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map.grid[game->map.player_pos.y][game->map.player_pos.x] = EMPTY;
	game->map.player_pos.x = new_x;
	game->map.player_pos.y = new_y;
	game->map.grid[new_y][new_x] = PLAYER;
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
}

int	move_player(t_game *game, int new_x, int new_y)
{
	char	target;

	if (new_x < 0 || new_x >= game->map.width
		|| new_y < 0 || new_y >= game->map.height)
		return (0);
	target = game->map.grid[new_y][new_x];
	if (target == WALL)
		return (0);
	if (target == COLLECTIBLE)
		game->collected++;
	if (target == EXIT)
	{
		if (game->collected == game->map.collectibles)
		{
			update_player_position(game, new_x, new_y);
			render_map(game);
			check_win_condition(game);
		}
		return (0);
	}
	update_player_position(game, new_x, new_y);
	render_map(game);
	return (1);
}
