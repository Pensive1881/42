/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:55:16 by acasper           #+#    #+#             */
/*   Updated: 2025/05/22 21:24:08 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char str = n + '0';

	int i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int     main(void)
{
	ft_putnbr_fd(42, 1);
        return (0);
}
