/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:08:46 by acasper           #+#    #+#             */
/*   Updated: 2025/02/25 20:52:58 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp1;
	int	temp2;

	temp1 = *a / *b;
	temp2 = *a % *b;
	*a = temp1;
	*b = temp2;
}

#include <stdio.h>

int	main(void)
{
	int num1;
	int num2;
	int *ptr1;
	int *ptr2;

	num1 = 4;
	num2 = 2;
	ptr1 = &num1;
	ptr2 = &num2;
	printf("%d %d", *ptr1, *ptr2);
	printf("%s", "\n");
	ft_ultimate_div_mod(ptr1, ptr2);
	printf("%d %d", *ptr1, *ptr2);
}
