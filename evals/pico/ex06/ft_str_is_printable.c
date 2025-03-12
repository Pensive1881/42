/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:56:22 by acasper           #+#    #+#             */
/*   Updated: 2025/03/02 23:13:13 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
write(1, str, 1);
write(1, "0\n", 2);
write(1, "1\n", 2);
*/
int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32)
		{
			return (0);
		}
		else if (*str > 127)
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
	char	*str1;
	char	*str2;

	str1 = "\n";
	str2 = "42";
//	ft_str_is_printable(argv[1]);
	ft_str_is_printable(str1);
	ft_str_is_printable(str2);
}
*/
