/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:14:45 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/02 15:36:00 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const	char	*s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	str = (char *)malloc(len + 1);
	if (str == 0)
	{
		return (NULL);
	}
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
//
// int	main(void)
// {
// 	char	S[] = "Hello world!";
// 	char	*A = ft_strdup(S);
//
// 	printf("%s\n", S);
// 	free(A);
// 	return (0);
// }
