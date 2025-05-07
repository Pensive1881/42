/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:38:36 by acasper           #+#    #+#             */
/*   Updated: 2025/02/27 21:02:09 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
#include <stdio.h>
write(1, dest, 1);
printf("\noutside: %s", dest);
*/

char	*ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest);
}

/*
#include <stdio.h>
int	main(void)
{
	char	str1[42];
	char	str2[] = "miau";

	printf("before string1: %s\n", str1);
	printf("before string2: %s\n", str2);
	ft_strcpy(str1, str2);
	printf("after string1: %s\n", str1);
	printf("after string2: %s\n", str2);
}
*/
