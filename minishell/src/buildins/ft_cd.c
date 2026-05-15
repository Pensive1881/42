/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:52:42 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/12 17:11:18 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cd(char **args, t_shell *shell)
{
	char	*home;
	char	*oldpwd;
	char	*newpwd;

	if (!args[1])
	{
		home = get_env_value(shell->env, "HOME");
		if (!home)
			return (1);
		chdir(home);
	}
	else if (ft_strncmp(args[1], "-", 1) == 0)
	{
		oldpwd = get_env_value(shell->env, "OLDPWD");
		if (!oldpwd)
		{
			ft_putendl_fd("Error: OLDPWD not set", 2);
			return (1);
		}
		chdir(oldpwd);
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			ft_putendl_fd("Error: no uch file or directory", 2);
			return (1);
		}
		else
		{
			oldpwd = get_env_value(shell->env, "PWD");
			update_env(shell->env, "OLDPWD", oldpwd);
			chdir(args[1]);
			newpwd = getcwd(NULL, 0);
			update_env(shell->env, "PWD", newpwd);
			free(newpwd);
		}
	}
	return (0);
}
