#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10000

int	main(int ac, char *av)
{
	int	i, j, r, keep, len;
	char	buf[BUFFER_SIZE + 1000];

	if (ac != 2 || !av[1][0])
		return (1);
	len = strlen(av[1]);
	keep = 0;
	while (r = read(0, buf + keep, BUFFER_SIZE) > 0)
	{
		r += keep;
		i = 0;
		while (i < len)
		{
			if (i <= r - len && memmem(buf + i, len, av[1], len))
			{
				j = 0;
				while (j < len)
				{
					write(1, "*", 1);
					j++;
				}
			}
			else if (i <= r - len)
			{
				write(1, &buf[i], 1);
				i++;
			}
			else
				break;
		}
		keep = r - i;
		j = 0;
		while (j < keep)
		{
			buf[j] = buf[i + j];
			j++;
		}
	}
	if (r < 0)
		return (fprintf(stderr, "Error: "), perror(""), 1);
	if (keep > 0)
		write (1, buf, keep);
	return (0);
}
