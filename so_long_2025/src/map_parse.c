/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:58:00 by acasper           #+#    #+#             */
/*   Updated: 2025/12/23 22:02:18 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*read_line_trim(int fd)
{
	char	*line;
	char	*trimmed;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		trimmed = ft_substr(line, 0, len - 1);
		free(line);
		return (trimmed);
	}
	return (line);
}

static int	allocate_map(t_game *game, int height)
{
	game->map.grid = (char **)malloc(sizeof(char *) * (height + 1));
	if (!game->map.grid)
		return (0);
	game->map.grid[height] = NULL;
	game->map.height = height;
	return (1);
}

static int	read_map_lines(int fd, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	line = read_line_trim(fd);
	while (line)
	{
		if (i == 0)
			game->map.width = ft_strlen(line);
		if ((int)ft_strlen(line) != game->map.width)
		{
			free(line);
			return (0);
		}
		game->map.grid[i] = line;
		i++;
		line = read_line_trim(fd);
	}
	return (1);
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
