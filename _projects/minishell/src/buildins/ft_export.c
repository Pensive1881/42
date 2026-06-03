/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:53:32 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/21 14:11:24 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_export(char **env)
{
	int		i;
	char	*equal;

	i = 0;
	while (env[i])
	{
		equal = ft_strchr(env[i], '=');
		ft_putstr_fd("declare -x ", 1);
		if (equal)
		{
			write(1, env[i], equal - env[i] + 1);
			write(1, "\"", 1);
			ft_putstr_fd(equal + 1, 1);
			write(1, "\"", 1);
		}
		else
			ft_putstr_fd(env[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

static void	parsing_adding(char **args, int i, t_shell *shell)
{
	char	*name;
	char	*value;
	char	*equal;

	equal = ft_strchr(args[i], '=');
	if (equal)
	{
		name = ft_substr(args[i], 0, equal - args[i]);
		value = ft_strdup(equal + 1);
	}
	else
	{
		name = ft_strdup(args[i]);
		value = NULL;
	}
	if (get_env_value(shell->env, name))
		update_env(shell->env, name, value);
	else
		add_to_env(shell, name, value);
	free(name);
	free(value);
}

int	ft_export(char **args, t_shell *shell)
{
	int		i;

	if (!shell->env)
		return (1);
	if (!args[1])
		return (print_export(shell->env), 0);
	i = 1;
	while (args[i])
	{
		parsing_adding(args, i, shell);
		i++;
	}
	return (0);
}

static	char	*e_entry(char *name, char *value)
{
	char	*entry;
	char	*tmp;

	if (value)
	{
		tmp = ft_strjoin(name, "=");
		entry = ft_strjoin(tmp, value);
		free(tmp);
		return (entry);
	}
	return (ft_strdup(name));
}

void	add_to_env(t_shell *shell, char *name, char *value)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	while (shell->env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return ;
	j = 0;
	while (j < i)
	{
		new_env[j] = shell->env[j];
		j++;
	}
	new_env[j] = e_entry(name, value);
	new_env[j + 1] = NULL;
	free(shell->env);
	shell->env = new_env;
}
