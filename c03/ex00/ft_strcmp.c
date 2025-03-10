/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:31:06 by acasper           #+#    #+#             */
/*   Updated: 2025/03/06 23:28:00 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	difference;
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			
		}
		else
		{
			return (str1 - str2);
		}
	}

	return (0);
}

int	 main(void)
{
	char	string1;
	char	string2;

	string1 = "miaumiau";
	string2 = "miaumeow";
	ft_strcmp(string1, string2);

	return 0;
}
