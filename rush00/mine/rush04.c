/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:09:48 by acasper           #+#    #+#             */
/*   Updated: 2025/02/24 13:17:02 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rush(int x, int y)
{
	int	i;
	int	j;
	char	str;

	i =0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			
			ft_putch(str);
			j++;
		}
		ft_putch(str);
		i++;
	}


}

