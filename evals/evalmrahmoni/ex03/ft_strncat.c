/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:35:19 by acasper           #+#    #+#             */
/*   Updated: 2025/03/10 16:42:19 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*pointer;

	pointer = dest;
	while (*pointer)
		pointer++;
	i = 0;
	while (*src && i < nb)
	{
		*pointer = *src;
		pointer++;
		src++;
		i++;
	}
	*pointer = '\0';
	return (dest);
}

#include <stdio.h>
int	main(void)
{
	char	string1[42] = "miau";
	char	string2[42] = "meow";

	printf("%s\n", ft_strncat(string1, string2, 2));

	return (0);
}

