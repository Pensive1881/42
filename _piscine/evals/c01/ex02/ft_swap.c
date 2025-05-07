/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owali <owali@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:06:51 by owali             #+#    #+#             */
/*   Updated: 2025/02/23 21:57:29 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	*temp;
	int	var;

	var = 0;
	temp = &var;
	*temp = *b;
	*b = *a;
	*a = *temp;
}

#include "stdio.h"

int	main(void)
{
	int	*ptr1;
	int	*ptr2;
	int	val1;
	int	val2;

	val1 = 9;
	val2 = 8;
	ptr1 = &val1;
	ptr2 = &val2;
	printf("bef: %d %d", *ptr1, *ptr2);
	ft_swap(ptr1, ptr2);
	printf("aft: %d %d", *ptr1, *ptr2);
}

