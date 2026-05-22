/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:53:02 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/12 16:54:40 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exit(char **args, t_shell *shell)
{
	int	num;

	if (args[1] && args[2])
	{
		ft_putendl_fd("Error: too many arguments", 2);
		return (1);
	}
	if (args[1])
	{
		num = ft_atoi(args[1]);
		shell->should_exit = 1;
		return (num);
	}
	shell->should_exit = 1;
	return (0);
}

/*
int	ft_exit(char **args)
{
	int	num;

	if (!args)
	{
		exit(0);
	}
	if (args[2])
	{
		printf("%\n, Error: too many arguments");
		return (1);
	}
	else if (args[1])
	{
		if (!ft_isdigit(args[1]))
		{
			printf("%\n, Error: numeric value required");
			exit (1);
		}
		else
		{
			num = ft_atoi(args[1]);
			exit(num);
		}
	}
	return (0);
}
*/
