/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:01:57 by acasper           #+#    #+#             */
/*   Updated: 2026/02/20 15:12:56 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	
}

int	move_player(t_game *game, int new_x, int new_y)
{
	char	target;

	if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
		return (0);
	target = game->map.grid[][];
	if (target == WALL)
		return (0);
	if (target == COLLECTIBLE)
		game->collected++;
	if (target == EXIT)
	{
		if (game->collected == game->map.collectibles)
		{
			update_player_position(ga,e new_x, new_y);
			render_map(game);
			check_win_condition(game);
		}
		return (0);
	}
	update_player_position(game, new_x, new_y);
	render_map(game);
	return (1);
}

