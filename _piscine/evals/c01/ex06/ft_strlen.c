/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owali <owali@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:33:37 by owali             #+#    #+#             */
/*   Updated: 2025/02/23 21:47:24 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int length = 0;
	while(*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

#include "stdio.h"

int main()
{

	char	*arr ="11qwertydd";// arr_str;
	int len=	ft_strlen(arr);

	printf("%d", len);
}

