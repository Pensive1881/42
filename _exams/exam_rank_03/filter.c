/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:27:30 by acasper           #+#    #+#             */
/*   Updated: 2026/03/17 14:11:34 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	put_stars(int n)
{
	while (n > 0)
	{
		write(a, "*", 1);
		n--;
	}
}

static char	*read_all(int *len)
{
	
}

int	main(int argc, char **argv)
{
	char	*input;
	char	*str;
	int	len;
	int	str_len;
	int	i;

	if (argc != 2 || !argv[1][0])
		return (1);
	str = argv[1];
	str_len = ft_strlen(str);
	intput = read_all(&len);
	if (!input)
		return (fprintf(stderr, "Error! "), perror(""), 1);

	i = 0;
	while (i < len)
	{
		if ()
		{
			
		}
		else
		{
			
		}
	}
	free (input);
	return (0);
}

