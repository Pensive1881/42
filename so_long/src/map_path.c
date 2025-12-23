/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:58:00 by acasper           #+#    #+#             */
/*   Updated: 2025/12/23 22:19:23 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, int *collectibles)
{
	if (map[y][x] == WALL || map[y][x] == 'V')
		return ;
	if (map[y][x] == COLLECTIBLE)
		(*collectibles)++;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, collectibles);
	flood_fill(map, x - 1, y, collectibles);
	flood_fill(map, x, y + 1, collectibles);
	flood_fill(map, x, y - 1, collectibles);
}

static int	can_reach_exit(char **map, int exit_x, int exit_y)
{
	return (map[exit_y][exit_x] == 'V');
}

int	check_path(t_game *game)
{
	char	**map_copy;
	int		collectibles;
	int		result;

	map_copy = copy_map(&game->map);
	if (!map_copy)
		return (0);
	collectibles = 0;
	flood_fill(map_copy, game->map.player_pos.x,
		game->map.player_pos.y, &collectibles);
	result = (collectibles == game->map.collectibles
			&& can_reach_exit(map_copy, game->map.exit_pos.x,
				game->map.exit_pos.y));
	free_map(map_copy);
	return (result);
}
