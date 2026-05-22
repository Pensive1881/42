/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:52:42 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/21 14:09:00 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	helper(char	*args, t_shell *shell)
{
	char	*newpwd;
	char	*oldpwd;

	if (chdir(args) == -1)
	{
		ft_putendl_fd("Error: no such file or directory", 2);
		return (1);
	}
	oldpwd = get_env_value(shell->env, "PWD");
	update_env(shell->env, "OLDPWD", oldpwd);
	newpwd = getcwd(NULL, 0);
	update_env(shell->env, "PWD", newpwd);
	free(newpwd);
	return (0);
}

int	ft_cd(char **args, t_shell *shell)
{
	char	*home;
	char	*oldpwd;

	if (!args[1])
	{
		home = get_env_value(shell->env, "HOME");
		if (!home)
			return (1);
		return (helper(home, shell));
	}
	else if (ft_strncmp(args[1], "-", 1) == 0)
	{
		oldpwd = get_env_value(shell->env, "OLDPWD");
		if (!oldpwd)
			return (ft_putendl_fd("Error: OLDPWD not set", 2), 1);
		return (helper(oldpwd, shell));
	}
	return (helper(args[1], shell));
}
