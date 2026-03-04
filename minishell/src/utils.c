/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:28:35 by acasper           #+#    #+#             */
/*   Updated: 2026/03/04 18:30:32 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	count_words(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (count);
}

char	**split_args(char *input)
{
	char	**args;
	int i;
	int	j;
	int	start;

	args = malloc(sizeof(char *) * (count_words(input) + 1));
	if (!args)
		return (NULL);

	i = 0;
	while (input[i])
	{
		while (input[i] == ' ')
			i++;
		start = i;
		while (input[i] && input[i] != ' ')
			i++;
		if (i > start)
		{
			args[j] = strndup(&input[start], i - start);
			j++;
		}
	}

	args[j] = NULL;
	RETURN (args);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free (args);
}

