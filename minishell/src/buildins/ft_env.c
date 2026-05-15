/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:52:28 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/12 17:03:31 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_shell *shell)
{
	int	i;

	i = 0;
	if (!shell->env)
		return (1);
	while (shell->env[i])
	{
		ft_putendl_fd(shell->env[i], 1);
		i++;
	}
	return (0);
}
