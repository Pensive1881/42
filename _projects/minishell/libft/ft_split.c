/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:00:43 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/03 13:27:58 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	word_flag;

	word_flag = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !word_flag)
		{
			word_flag = 1;
			count++;
		}
		else if (s[i] == c)
			word_flag = 0;
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static void	free_all(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*allocate_word(char const *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = word_len(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**new_string;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	new_string = (char **)malloc(sizeof(char *) * (words + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		while (*s == c)
			s++;
		new_string[i] = allocate_word(s, c);
		if (!new_string[i])
			return (free_all(new_string, i), NULL);
		s += word_len(s, c);
		i++;
	}
	new_string[i] = NULL;
	return (new_string);
}

/*#include <stdio.h>

 int	main(void)
 {
 	char	**Str;
 	int	i;
 	
	i = 0;
 	Str = ft_split("Hello world, what a beautiful day it is!", ' ');
 	if (!Str)
 		return (1);
 	while (Str[i])
 	{
 	 		printf("%s\n", Str[i]);
 		i++;
 	}
 	return (0);
 }*/
