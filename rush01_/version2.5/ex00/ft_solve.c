/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsvelka <lsvelka@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:28:39 by lsvelka           #+#    #+#             */
/*   Updated: 2025/03/02 16:54:48 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checksudoku(int **matrix, int row, int col, int num);
int	ft_checkvisbility(int **matrix, int *inputArray);

int	ft_solve(int **matrix, int *inputArray, int row, int col)
{
	int	num;

	if (row == 4)
	{
		if (ft_checkvisbility(matrix, inputArray)) 
			return (1);
		return (0);
	}
	if (col == 4)
	{
		return (ft_solve(matrix, inputArray, row + 1, 0));
	}
	num = 1;
	while (num <= 4) 
	{
		if (ft_checksudoku(matrix, row, col, num)) 
		{
			matrix[row][col] = num;
			if (ft_solve(matrix, inputArray, row, col + 1))
				return (1);
			matrix[row][col] = 0;
		}
		num ++;
	}
	return (0);
}
