#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	char 	c;

	if (n >- 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

void	print_nqueens(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(board[i]);
		if (i < n - 1)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - row == i - col || board[i] - row == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	solve_nqueens(int *board, int col, int n)
{
	int	row;

	if (col >= n)
	{
		print_nqueens(board, n);
		return ;
	}
	row = 0;
	while (row < n)
	{
		if (is_safe(board, row, col))
		{
			board[col] = row;
			solve_nqueens(board, col + 1, n);
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	*board;
	int	n;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	if (n <= 0)
		return (1);
	board = malloc(n * sizeof(int));
	if (!board)
		return (1);
	solve_nqueens(board, 0, n);
	free(board);
	return (0);
}
