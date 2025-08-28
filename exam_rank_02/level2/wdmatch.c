#include <unistd.h>

void	wdmatch(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		
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

