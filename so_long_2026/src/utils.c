/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:59:06 by acasper           #+#    #+#             */
/*   Updated: 2026/01/23 16:07:18 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char *line)
{
	int	width;

	width = 0;
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}

int	get_map_height(char *filename)
{
	int	fd;
	int	height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}	
	close(fd);
	return (height);
}
