#include <unistd.h>

void	capitalizer(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i] == ' '))
			str[i] -= 'a'- 'A';
		write(1, &str[i], 1);
		i++;
	}
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
