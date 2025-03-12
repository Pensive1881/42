/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:41:34 by acasper           #+#    #+#             */
/*   Updated: 2025/03/05 19:51:14 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <stdio.h>
int	main(void)
{
	int	num = 4;
	char	str1[42];
	char	str2[] = "miaumeow";

//	printf("before string1: %s\n", str1);
	printf("before string2: %s\n", str2);
//	ft_strncpy(str1, str2, num);
//	printf("after string1: %s\n", str1);
//	printf("after string2: %s\n", str2);

	printf("Returned dest: %s\n", ft_strncpy(str1, str2, num));

	num = 12;

//	printf("before string1: %s\n", str1);
	printf("before string2: %s\n", str2);
	ft_strncpy(str1, str2, num);
//	printf("after string1: %s\n", str1);
//	printf("after string2: %s\n", str2);

	printf("Returned dest: %s\n", ft_strncpy(str1, str2, num));


	return (0);
}

