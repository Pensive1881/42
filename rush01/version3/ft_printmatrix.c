/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamedin <mhamedin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:54:30 by mhamedin          #+#    #+#             */
/*   Updated: 2025/03/02 16:01:40 by mhamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printmatrix(int **matrix)
{
	int		i;
	int		j;
	char	num;

	i = 0;
	num = '0';
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
