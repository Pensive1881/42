/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamedin <mhamedin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:01:47 by mhamedin          #+#    #+#             */
/*   Updated: 2025/03/02 19:04:55 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_sudoku(int **matrix, int row, int col, int num);
int	ft_check_visibility(int **matrix, int *inputArray);
int	ft_try_number(int **matrix, int *inputArray, int row, int col);

int	ft_solve(int **matrix, int *inputArray, int row, int col)
{
	if (row == 4)
	{
		if (ft_check_visibility(matrix, inputArray))
		{
			return (1);
		}
		return (0);
	}
	if (col == 4)
	{
		return (ft_solve(matrix, inputArray, row + 1, 0));
	}
	return (ft_try_number(matrix, inputArray, row, col));
}

int	ft_try_number(int **matrix, int *inputArray, int row, int col)
{
	int	num;

	num = 1;
	while (num <= 4)
	{
		if (ft_check_sudoku(matrix, row, col, num))
		{
			matrix[row][col] = num;
			if (ft_solve(matrix, inputArray, row, col + 1))
			{
				return (1);
			}
			matrix[row][col] = 0;
		}
		num++;
	}
	return (0);
}
