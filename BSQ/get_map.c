/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbigeon <mbigeon@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:16:18 by mbigeon           #+#    #+#             */
/*   Updated: 2025/03/12 15:16:48 by mbigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

void	get_data(const char *filename, int *height, int *width, char ***map)
{
	int		fd;
	char	*ptr;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(1);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read <= 0)
	{
		close(fd);
		exit(1);
	}
	buffer[bytes_read] = '\0';
	ptr = buffer;
	find_values(&ptr, height, width);
	get_map(map, *width, *height, &ptr);
	close(fd);
}

void	find_values(char **ptr, int *height, int *width)
{
	int	num;

	num = 0;
	while (**ptr >= '0' && **ptr <= '9')
	{
		num = num * 10 + (**ptr - '0');
		(*ptr)++;
	}
	*height = num;
	while (**ptr && **ptr != '\n')
		(*ptr)++;
	(*ptr)++;
	*width = 0;
	while ((*ptr)[*width] && (*ptr)[*width] != '\n')
		(*width)++;
}

void	get_map(char ***map, int width, int height, char **ptr)
{
	int	i;
	int	j;

	i = 0;
	*map = (char **)malloc(height * sizeof(char *));
	if (!(*map))
		exit(1);
	while (i < height)
	{
		(*map)[i] = (char *)malloc(width + 1);
		if (!(*map)[i])
			exit(1);
		while (**ptr && **ptr != '\n')
			(*ptr)++;
		(*ptr)++;
		j = 0;
		while (j < width)
		{
			(*map)[i][j] = **ptr;
			(*ptr)++;
			j++;
		}
		(*map)[i][width] = '\0';
		i++;
	}
}
