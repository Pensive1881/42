/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sudoku.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamedin <mhamedin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:36:57 by mhamedin          #+#    #+#             */
/*   Updated: 2025/03/02 15:38:45 by mhamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
