#include <unistd.h>

void	inter(char *str1, char *str2)
{
	int	i;
	int	j;
	int	duplicate;

	i = 0;
	while (str1[i])
	{
		duplicate = 0;
		j = 0;
		while ([str2[j] && duplicate == 0)
		{
			if (str1[i] == str2[j])
			{
				write(1, &str1[i], 1);
				duplicate = 1;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 0);
	else
		inter(argv[1], argv[2]);

	return (0);
}

