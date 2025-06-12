/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:57:22 by acasper           #+#    #+#             */
/*   Updated: 2025/06/12 17:28:32 by acasper          ###   ########.fr       */
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
	//
}

static char *amend_stash(char *stash)
{
	//
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
