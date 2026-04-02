#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int i, j, r;
	int len;
	char buf[1000000];

	if (ac != 2 || !av[1][0])
		return (1);
	r = read(0, buf, 1000000);
	if (r < 0)
		return (fprintf(stderr, "Error! "), perror (""), 1);
	len = strlen(av[1]);
	i = 0;
	while (i < r)
	{
		if (i <= r - len && !memcmp(buf + i, av[1], len))
		{
			j = 0;
			while (j < len)
			{
				write(1, "*", 1);
				j++;
			}
			i += len;
		}
		else
		{
			write(1, &buf[i], 1);
			i++;
		}
	}
	return (0);
}
