/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:29:23 by acasper           #+#    #+#             */
/*   Updated: 2026/01/20 18:29:36 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	count_map_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->collectibles = 0;
	map->exits = 0;
	map->player = 0;
	while ()
	{
		j = 0;
		while ()
		{
			if ()
			{
				
			}
			else if ()
			{
				
			}
			else if ()
			{
				
			}
			else if ()
				return (0);
			j++;
		}
		i++;
	}
	if ()
		return (0);
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	int	i;

	i = 0;
	while ()
	{
		if ()
			return (0);
		i++;
	}
	i = 0;
	while ()
	{
		if ()
			return (0);
		i++;
	}
	return (1);
}

int	map_validate(t_game *game)
{
	if (gmae->map.height < 3 || game->map.width < 3)
		return (0);
	if (!is_surrounded_by_walls(&game->map))
		return (0);
	return (1);
}

