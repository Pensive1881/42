#include <unistd.h>

void	capitalizer(char *str)
{
	
}

int     main(int argc, char **argv)
{
	int     i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (i < argc)
	{
		capitalizer(argv[i]);
		write (1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
