/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsvelka <lsvelka@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:04:09 by lsvelka           #+#    #+#             */
/*   Updated: 2025/03/02 18:06:12 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_printmatrix(int **matrix);
int		ft_checkSudoku(int **matrix, int row, int col, int num);
int		ft_checkVisbility(int **matrix, int *inputArray);
void	ft_assign(int size, int *array, int *inputArray);
int		ft_is_valid(int **matrix, int row, int col, int num);
int		ft_solve(int **matrix, int *inputArray, int row, int col);

int	ft_checkinput(char *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4') 
		{
			counter++;
		}
		else if (str[i] != ' ' && str[i] != '\0') 
		{
			return (0);
		}
		i++;
	}
	if (counter != 16)
		return (0);
	return (1);
}

int	**ft_creatematrix(void)
{
	int	rows;
	int	cols;
	int	**arr;
	int	i;

	rows = 4;
	cols = 4;
	arr = (int **)malloc(rows * sizeof(int *));
	i = 0;
	while (i < rows)
	{
		arr[i] = (int *)malloc(cols * sizeof(int));
		i++;
	}
	return (arr);
}

void	ft_convert(int *inputArray, char *input)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (input[i] != '\0')
	{
		if (input[i] != ' ')
		{
			inputArray[k] = input[i] - '0';
			k++;
		}
		i++;
	}
}

void	ft_fillwithzeros(int **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	inputarray[16];
	int	**matrix;

	if (argc == 2 || ft_checkinput(argv[1]) == 0)
	{
		write(1, "Incorrect input\n", 16); 
		return (0);
	}
	matrix = ft_creatematrix();
	if (!matrix)
	{
		write(1, "Memory allocation error\n", 24);
		return (0);
	}
	ft_convert(inputarray, argv[1]);
	ft_fillwithzeros(matrix);
	if (ft_solve(matrix, inputarray, 0, 0) == 1) 
		ft_printmatrix(matrix);
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
}
