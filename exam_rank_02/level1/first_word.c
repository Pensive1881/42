/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:46:37 by acasper           #+#    #+#             */
/*   Updated: 2025/08/19 16:21:00 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	first_word(char *word)
{
	int	i;

	i = 0;
	while (word[i] == ' ' || word[i] == '\t')
		i++;
	while (word[i] != '\0' && word[i] != ' ' && word[i] != '\t')
	{
		write(1, &word[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		write (1, "\n", 1);
		return (0);
	}
	else
		first_word(argv[1]);

	return (0);
}

