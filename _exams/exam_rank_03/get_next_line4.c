#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
#endif

char	get_next_line(int fd)
{
	static int	i = 0;
	static int	size = 0;
	static char	buffer[BUFFER_SIZE + 1];
	int	j = 0;
	char	*line;

	if (fd < 0)
		return (NULL);
	line  malloc(10000);
	if (!line)
		return (NULL);
	while (1)
	{
		if (i >= size)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			i = 0;
			if (size <= 0)
				break;
		}
		line[j++] = buffer[i];
		if (buffer[i++] == '\n')
			break;
		
	}
	if (j == 0)
	{
		free(line);
		return (NULL);
	}
	line[j] = '\0';
	return (line);
}
