/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:54:07 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/12 17:10:00 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(char **args, t_shell *shell)
{
	int	i;
	int	j;
	int	len;

	if (!*args)
		return (0);
	i = 1;
	len = ft_strlen(args[i]);
	while (args[i])
	{
		j = 0;
		while (shell->env[j])
		{
			if (ft_strncmp(shell->env[j], args[i], len) == 0 
				&& shell->env[j][len] == '=')
			{
				while (shell->env[j + 1])
				{
					shell->env[j] = shell->env[j + 1];
					j++;
				}
				shell->env[j] = NULL;
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
