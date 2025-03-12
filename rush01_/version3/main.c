/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamedin <mhamedin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:05:50 by mhamedin          #+#    #+#             */
/*   Updated: 2025/03/02 19:02:44 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_printmatrix(int **matrix);
int		ft_check_sudoku(int **matrix, int row, int col, int num);
int		ft_check_visibility(int **matrix, int *input_array);
void	ft_assign(int size, int *array, int *input_array);
int		ft_is_valid(int **matrix, int row, int col, int num);
int		ft_solve(int **matrix, int *input_array, int row, int col);

int	ft_check_input(char *str)
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

void	ft_convert(int *input_array, char *input)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (input[i] != '\0')
	{
		if (input[i] != ' ')
		{
			input_array[k] = input[i] - '0';
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
	int	input_array[16];
	int	**matrix;

	if (argc < 2 || ft_check_input(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	matrix = ft_creatematrix();
	if (!matrix)
	{
		write(1, "Memory allocation error\n", 24);
		return (0);
	}
	ft_convert(input_array, argv[1]);
	ft_fillwithzeros(matrix);
	if (ft_solve(matrix, input_array, 0, 0) == 1)
		ft_printmatrix(matrix);
	else
		write(1, "Error\n", 6);
	return (0);
}
