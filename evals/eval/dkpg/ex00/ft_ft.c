/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:54:28 by acasper           #+#    #+#             */
/*   Updated: 2025/02/24 00:05:58 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
/*
#include <stdio.h>
int	main(void)
{
	int	some_num;
	int	*num;

	some_num = 69;
	num = &some_num;
	printf("%d", *num);
	printf("\n");
	ft_ft(num);
	printf("%d", *num);
}
*/
