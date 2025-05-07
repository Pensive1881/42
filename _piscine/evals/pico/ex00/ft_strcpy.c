/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:30:10 by acasper           #+#    #+#             */
/*   Updated: 2025/03/05 19:06:53 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>
int	main(void)
{
	char	str1[42];
	char	str2[] = "miau";

//	printf("before string1: %s\n", str1);
	printf("before string2: %s\n", str2);
	ft_strcpy(str1, str2);
//	printf("after string1: %s\n", str1);
//	printf("after string2: %s\n", str2);

	printf("Returned dest: %s\n", ft_strcpy(str1, str2));
}

