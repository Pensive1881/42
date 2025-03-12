/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:33:15 by acasper           #+#    #+#             */
/*   Updated: 2025/03/10 16:48:38 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n <= 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (n <= i)
		return (0);
	return (s1[i] - s2[i]);
}

#include <stdio.h>
int	main(void)
{
	char	string1[42] = "miaumiau";
	char	string2[42] = "miaumeow";

	printf("%d\n", ft_strncmp(string1, string2, 2));
	printf("%d\n", ft_strncmp(string1, string2, 6));

	return (0);
}

