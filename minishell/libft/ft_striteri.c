/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:32:40 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/02 18:29:52 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*#include <stdio.h>

void	sample_function(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32; // convert to uppercase
}

int	main(void)
{
	char str[] = "hello, world!";

	printf("Before: %s\n", str);
	ft_striteri(str, sample_function);
	printf("After : %s\n", str);

	return 0;
}//*/
