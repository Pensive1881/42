/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:30:21 by acasper           #+#    #+#             */
/*   Updated: 2026/01/20 18:30:40 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static char	*read_line_trim(int fd)
{
	
}

static int	allocate_map(t_game *game, int height)
{
	
}

static int	read_map_line(int fd, t_game *game))
{
	
}

int	parse_map(char *filename, t_game *game)
{
	int	fd;
	int	height;

	height = get_map_height(filename);
	if (height == 0)
		return (0);
	if (!allocate_map(game, height))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(game->map.grid);
		return (0);
	}
	if (!read_map_lines(fd, game))
	{
		free_map(game->map.grid);
		game->map.grid = NULL;
		close(fd);
		return (0);
	}
	close(fd);
	return (count_map_elements(&game->map));
}

