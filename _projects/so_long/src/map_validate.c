/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:29:23 by acasper           #+#    #+#             */
/*   Updated: 2026/02/23 16:20:49 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	handle_tile(t_map *map, int i, int j)
{
	if (map->grid[i][j] == PLAYER)
	{
		map->players++;
		map->player_pos.x = j;
		map->player_pos.y = i;
	}
	else if (map->grid[i][j] == EXIT)
	{
		map->exits++;
		map->exit_pos.x = j;
		map->exit_pos.y = i;
	}
	else if (map->grid[i][j] == COLLECTIBLE)
		map->collectibles++;
	else if (map->grid[i][j] != WALL && map->grid[i][j] != EMPTY)
		return (0);
	return (1);
}

int	count_map_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->collectibles = 0;
	map->exits = 0;
	map->players = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!handle_tile(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	if (map->players != 1 || map->exits != 1 || map->collectibles < 1)
		return (0);
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != WALL || map->grid[map->height - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != WALL || map->grid[i][map->width - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (game->map.height < 3 || game->map.width < 3)
		return (0);
	if (!is_surrounded_by_walls(&game->map))
		return (0);
	return (1);
}
