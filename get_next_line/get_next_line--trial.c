/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:52:20 by acasper           #+#    #+#             */
/*   Updated: 2025/06/17 20:02:46 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	int		bytes;

	if (!stash && !(stash = ft_strdup("")))
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(stash), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	if (stash[0] == '\0')
		return (free(stash), NULL);
	return (stash);
}

static char	*push_line(char *stash)
{
	int		i;
	size_t	has_nl;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	has_nl = (stash[i] == '\n');
	line = malloc(i + has_nl + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, i + has_nl);
	line[i + has_nl] = '\0';
	return (line);
}

static char	*amend_stash(char *stash)
{
	int		i;
	char	*rest;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i++])
		return (free(stash), NULL);
	rest = ft_strdup(stash + i);
	return (free(stash), rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = push_line(stash);
	stash = amend_stash(stash);
	return (line);
}
