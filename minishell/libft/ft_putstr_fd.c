/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:20:44 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/02 18:21:05 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char	*s, int fd)
{
	if (!*s)
	{
		return ;
	}
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}
/*
int	main(void)
{
	char	*msg = "Hello World!";

	ft_putstr_fd(msg, 1);
	write (1, "\n", 1);
	return (0);
}*/
