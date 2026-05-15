/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:52:08 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/12 17:03:04 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(char **args)
{
	int	i;
	int	no_newline;

	if (!args || !args[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	no_newline = 0;
	if (ft_strncmp(args[1], "-n", 2) == 0)
	{
		no_newline = 1;
		i = 2;
	}
	else
		i = 1;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!no_newline)
		write(1, "\n", 1);
	return (0);
}
