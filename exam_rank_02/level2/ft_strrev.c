/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:43:14 by acasper           #+#    #+#             */
/*   Updated: 2025/09/16 21:34:03 by acasper          ###   ########.fr       */
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
	while (i > j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}


#include <stdio.h>

int	main(void)
{
	printf("miaumeow: %s", ft_strrev("miaumeow"));

	return (0);
}
