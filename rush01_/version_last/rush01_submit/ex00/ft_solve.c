/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamedin <mhamedin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:10:57 by mhamedin          #+#    #+#             */
/*   Updated: 2025/03/02 19:17:14 by mhamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printmatrix(int **matrix);
int		ft_check_visibility(int **matrix, int *input_array);
int		ft_check_sudoku(int **matrix, int row, int col, int num);

void	ft_assign(int *array, int *input_array)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		array[i] = input_array[i];
		i++;
	}
}

int	ft_solve(int **matrix, int *input_array, int row, int col)
{
	int	num;

	if (row == 4)
	{
		if (ft_check_visibility(matrix, input_array))
			return (1);
		return (0);
	}
	if (col == 4)
		return (ft_solve(matrix, input_array, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		if (ft_check_sudoku(matrix, row, col, num))
		{
			matrix[row][col] = num;
			if (ft_solve(matrix, input_array, row, col + 1))
				return (1);
			matrix[row][col] = 0;
		}
		num ++;
	}
	return (0);
}
