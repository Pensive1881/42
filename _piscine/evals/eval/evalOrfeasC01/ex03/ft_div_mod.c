/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:08:19 by acasper           #+#    #+#             */
/*   Updated: 2025/02/25 20:52:15 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}


#include <stdio.h>

int	main(void)
{
	int	num1;
	int	num2;
	int	*ptr1;
	int	*ptr2;

	num1 = 4;
	num2 = 2;
	ptr1 = &num1;
	ptr2 = &num2;
	printf("%d %d", *ptr1, *ptr2);
	printf("%s", "\n");
	ft_div_mod(num1, num2, ptr1, ptr2);
	printf("%d %d", *ptr1, *ptr2);
}
