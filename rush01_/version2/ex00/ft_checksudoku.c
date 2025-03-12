/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkSudoku.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsvelka <lsvelka@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:18:34 by lsvelka           #+#    #+#             */
/*   Updated: 2025/03/02 15:21:35 by lsvelka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checksudoku(int **matrix, int row, int col, int num)
{
	int		i;

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
