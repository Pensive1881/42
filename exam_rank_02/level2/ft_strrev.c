/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:43:14 by acasper           #+#    #+#             */
/*   Updated: 2025/09/16 21:38:28 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strrev(char *str)
{
	char	temp;
	int len;
	int	i;

	len = 0;
	while (str[len])
		len++;
	len--;
	i = 0;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}


#include <stdio.h>

int	main(void)
{
	char	s1[] = "miaumeow";
	printf("miaumeow: %s", ft_strrev(s1));

	return (0);
}
