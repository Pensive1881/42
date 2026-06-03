/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:43:31 by acasper           #+#    #+#             */
/*   Updated: 2026/05/12 16:33:32 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = malloc(sizeof(char *));
	if (!cmd->argv)
	{
		free(cmd);
		return (NULL);
	}
	cmd->argv[0] = NULL;
	cmd->argc = 0;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

static int	copy_old_args(char **new_argv, char **old_argv, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		new_argv[i] = old_argv[i];
		i++;
	}
	return (1);
}

int	add_word_to_cmd(t_cmd *cmd, char *word)
{
	char	**new_argv;

	new_argv = malloc(sizeof(char *) * (cmd->argc + 2));
	if (!new_argv)
		return (0);
	copy_old_args(new_argv, cmd->argv, cmd->argc);
	new_argv[cmd->argc] = ft_strdup(word);
	if (!new_argv[cmd->argc])
	{
		free(new_argv);
		return (0);
	}
	new_argv[cmd->argc + 1] = NULL;
	free(cmd->argv);
	cmd->argv = new_argv;
	cmd->argc++;
	return (1);
}

int	add_redir_to_cmd(t_cmd *cmd, t_redir *redir)
{
	t_redir	*last;

	if (!cmd || !redir)
		return (0);
	if (!cmd->redirs)
	{
		cmd->redirs = redir;
		return (1);
	}
	last = cmd->redirs;
	while (last->next)
		last = last->next;
	last->next = redir;
	return (1);
}

t_cmd	*free_cmd_and_null(t_cmd *cmd)
{
	free_cmds(cmd);
	return (NULL);
}
