#include <unistd.h>

void	wdmatch(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j]
				)
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}


int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
		wdmatch(argv[1], argv[2]);
	return (0);
}

