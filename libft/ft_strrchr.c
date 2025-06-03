/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:44:19 by acasper           #+#    #+#             */
/*   Updated: 2025/06/03 13:37:53 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_char;

	last_char = NULL;
	if (c == '\0')
		return ((char *) s);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			last_char = (char *) s;
		i++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (last_char);
}

/*
int     main()
{
        return (0);
}
*/
