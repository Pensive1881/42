/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:52:26 by rrajni            #+#    #+#             */
/*   Updated: 2025/05/19 18:48:19 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *) str;
	while (n != 0)
	{
		*s = 0;
		s++;
		n--;
	}
}

/*#include <stdio.h>
  int	main(void)
  {
  char	Str[10] = "Hello hihi";
  size_t	i;

  ft_bzero(Str, 7);
  i = 0;
  while (i < 10)
  {
  printf("%c", Str[i]);
  i++;
  }
  printf("\n");
  return (0);
  }*/
