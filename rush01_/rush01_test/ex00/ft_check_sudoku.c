/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkSudoku.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamedin <mhamedin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:02:44 by mhamedin          #+#    #+#             */
/*   Updated: 2025/03/02 17:17:59 by mhamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printmatrix(int **matrix);
void	ft_assign(int *array, int *input_array);

int	ft_check_sudoku(int **matrix, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (matrix[row][i] == num || matrix[i][col] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
