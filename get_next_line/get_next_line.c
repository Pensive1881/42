/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:57:22 by acasper           #+#    #+#             */
/*   Updated: 2025/06/17 17:15:09 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*
static char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes;
	char	*tmp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while ((stash == NULL || !ft_strchr(stash, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
	}
	free(buffer);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (stash);
}
*/

static char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), NULL);
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
		return (NULL);
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
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_stash(fd, stash);
	if (!stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	next_line = push_line(stash);
	stash = amend_stash(stash);
	return (next_line);
}

/*
int	main(void)
{
	return (0);
}
*/
