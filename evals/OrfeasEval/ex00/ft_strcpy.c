/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:30:10 by acasper           #+#    #+#             */
/*   Updated: 2025/03/04 21:39:40 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

#include <stdio.h>
int	main(void)
{
	char	str1[4];
	char	str2[] = "miau";

	printf("before string1: %s\n", str1);
	printf("before string2: %s\n", str2);
	ft_strcpy(str1, str2);
	printf("after string1: %s\n", str1);
	printf("after string2: %s\n", str2);
}

