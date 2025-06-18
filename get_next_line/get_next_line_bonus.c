/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:01:54 by acasper           #+#    #+#             */
/*   Updated: 2025/06/18 15:35:42 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*normilicious(char *stash)
{
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	int		bytes;

	stash = normilicious(stash);
	if (!stash)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while ((!ft_strchr(stash, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(stash), NULL);
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
	}
	free(buffer);
	if (!stash || !stash[0])
		return (free(stash), NULL);
	return (stash);
}

static char	*push_line(char *stash)
{
	int		i;
	int		j;
	size_t	has_nl;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	has_nl = (stash[i] == '\n');
	line = (char *)malloc((i + has_nl + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (has_nl)
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*amend_stash(char *stash)
{
	int		i;
	int		j;
	char	*return_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	return_stash = (char *)malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!return_stash)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		return_stash[j++] = stash[i++];
	return_stash[j] = '\0';
	free(stash);
	return (return_stash);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*stash[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	next_line = push_line(stash[fd]);
	stash[fd] = amend_stash(stash[fd]);
	return (next_line);
}
