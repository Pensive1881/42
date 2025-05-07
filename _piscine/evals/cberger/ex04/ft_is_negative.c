/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberger <cberger@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:23:57 by cberger           #+#    #+#             */
/*   Updated: 2025/03/06 23:38:37 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}
	else 
	{
		write(1, "P", 1);
	}
}
int	main(void)
{
	ft_is_negative(99);
	printf("\n");
	ft_is_negative(0);
	printf("\n");
	ft_is_negative(-1);
	printf("\n");
	return (0);
}

