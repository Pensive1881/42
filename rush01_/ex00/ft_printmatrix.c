#include <unistd.h>

void	ft_printmatrix(int **matrix)
{
	char	num;
	int		i;
	int		j;

	i = 0;
	while (i < 4) 
	{
		j = 0;
		while (j < 4) 
		{
			num = matrix[i][j] + '0';
			write(1, &num, 1);
			if (j != 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
