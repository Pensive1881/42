/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:31:24 by acasper           #+#    #+#             */
/*   Updated: 2026/01/20 18:31:36 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static char	**copy_map(t_map *map)
{
	char	**copy;
	int	i;

	copy = ()malloc();
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, int *collectibles)
{
	
}

static int	can_reach_exit(char **map, int exit_x, int ext_y)
{
	return (map[exit_y][exit_x] == 'V');
}

int	check_path(t_game *game)
{
	char	**map_copy;
	int	collectibles;
	int	result;

	map_copy = copy_map(&game->map);
	if (!map_copy)
		return (0);
	collectibles = 0;
	flood_fill(map_copy, game->map.player_pos.x,
		game->map.player_pos.y, &collectibles);
	result = (collectibles == game->map.collectibles
			&& can_reach_exit(map_copy, game->map.exit_pos.x,
				game->map.exit_pos_y));
	free_map(map_copy);
	return (result);
}
