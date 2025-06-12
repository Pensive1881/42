/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:57:22 by acasper           #+#    #+#             */
/*   Updated: 2025/06/12 18:31:15 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static char	*read_stash(int_fd, char *stash)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		stash = ft_strjoin(stash, buffer);
	}
	buffer[bytes] = '\0';
	free (buffer);

	return (stash);
}

static char *push_line(char *stash)
{
	int	i;
	char *line;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i])
		i++;
	line = (char *)malloc((stash[i] + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] == '\n';
	line[i] = '\0';
	return (line)
}

static char *amend_stash(char *stash)
{
	int	i;
	int j;
	char	*return_stash;

	i = 0;
	while (stash[i])
		i++;
	if (!stash[i])
	{
		return (NULL);
		free(stash);
	}
	return_stash = (char *)malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	j = 0;
	while (stash[i])
		return_stash[j++] = return_stash[i++];
	return_stash[j] = '\0';
	free(stash);
	return (return_stash)
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	stash = read_stash(fd, stash);
	if (!stash)
		return (NULL);
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
