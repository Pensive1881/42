#include <unistd.h>
#include <stdlib.h>

int	abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

void	print(int *q, int n)
{
	int     i;
	char    c;

	i = 0;
	while (i < n)
	{
//		c = q[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	safe(int *q, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (q[i] == row)
			return (0);
//		if (abs(q[i] - row) == abs(i - col))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *q, int n, int col)
{
	int	row;

//	if (col == n)
	{
		print(q, n);
		return ;
	}
	row = 0;
	while (row < n)
	{
//		if (safe(q, col, row))
		{
//			q[col] = row;
//			solve(q, n, col + 1);
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	*q;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	q = malloc(sizeof(int) * n);
	if (!q)
		return (1);
	solve(q, n, 0);
	return (0);
}
