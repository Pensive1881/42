/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsvelka <lsvelka@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:23:12 by lsvelka           #+#    #+#             */
/*   Updated: 2025/03/02 15:23:26 by lsvelka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printmatrix(int **matrix)
{
	char	num;
	int		i;
	int		j;

	i = 0;
	while (i < 4) 
	{
		j = 0;
		while (j < 4) 
		{
			num = matrix[i][j] + '0';
			write(1, &num, 1);
			if (j != 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
