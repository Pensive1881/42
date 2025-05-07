/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:54:05 by acasper           #+#    #+#             */
/*   Updated: 2025/03/02 23:09:18 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
write(1, "\n0", 2);
write(1, "\n1", 2);
*/
int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (*str < 65)
		{
			return (0);
		}
		else if (*str > 90)
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	ft_str_is_uppercase(argv[1]);
}
*/
