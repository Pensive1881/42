/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:07:43 by acasper           #+#    #+#             */
/*   Updated: 2025/02/25 22:18:16 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp1;
	int	temp2;

	temp1 = *a;
	temp2 = *b;
	*a = temp2;
	*b = temp1;
}

#include <stdio.h>

int main(void)
{
	int	num1;
	int	num2;
	int	*ptr1;
	int	*ptr2;

	num1 = 4;
	num2 = 2;
	ptr1 = &num1;
	ptr2 = &num2;
	printf("%d %d\n", num1, num2);
	ft_swap(ptr1, ptr2);
	printf("%d %d", num1, num2);
}
