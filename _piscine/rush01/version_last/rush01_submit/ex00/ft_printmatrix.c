/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamedin <mhamedin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:10:06 by mhamedin          #+#    #+#             */
/*   Updated: 2025/03/02 17:19:43 by mhamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printmatrix(int **matrix);
void	ft_assign(int *array, int *input_array);

void	ft_printmatrix(int **matrix)
{
	char	num;
	int		i;
	int		j;

	num = '0';
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			num = matrix[i][j] + '0';
			write(1, &num, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
