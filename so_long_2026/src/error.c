/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:58:46 by acasper           #+#    #+#             */
/*   Updated: 2026/01/20 16:17:55 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_exit(char *message)
{
	ft_putendl_fd(mesage, 2);
	exit(1);
}

void	cleanup_game(t_game *game)
{
	if (game->map.grid)
		free_map(game->map.grid);
	if (game->mlx)
	{
		free_textures(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
