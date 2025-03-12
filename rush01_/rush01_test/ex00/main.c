/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamedin <mhamedin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:12:57 by mhamedin          #+#    #+#             */
/*   Updated: 2025/03/02 19:17:24 by mhamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_printmatrix(int **matrix);
void	ft_assign(int *array, int *input_array);
int		ft_check_sudoku(int **matrix, int row, int col, int num);
int		ft_handle_error(const char *message, int len);
int		ft_check_visibility(int **matrix, int *input_array);
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

int	**ft_creatematrix(void)
{
	int	rows;
	int	cols;
	int	**arr;
	int	i;

	i = 0;
	cols = 4;
	rows = 4;
	arr = (int **)malloc(rows * sizeof(int *));
	while (i < rows)
	{
		arr[i] = (int *)malloc(cols * sizeof(int));
		i++;
	}
	return (arr);
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

	if (argc < 2)
		return (ft_handle_error("No input\n", 6));
	if (ft_check_input(argv[1]) == 0)
		return (ft_handle_error("Incorrect input\n", 16));
	matrix = ft_creatematrix();
	if (!matrix)
		return (ft_handle_error("Memory allocation error\n", 24));
	ft_convert(input_array, argv[1]);
	ft_fillwithzeros(matrix);
	if (ft_solve(matrix, input_array, 0, 0) == 1)
		ft_printmatrix(matrix);
	else
		write(1, "Error\n", 6);
	return (0);
}
