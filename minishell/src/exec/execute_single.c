/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:00:07 by acasper           #+#    #+#             */
/*   Updated: 2026/05/25 17:12:40 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	exec_external(t_cmd *cmd, t_shell *shell)
{
	char	*path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		clean_exit(shell, 1);
	path = find_command_path(cmd->argv[0], shell->env);
	if (!path)
	{
		print_exec_error(cmd->argv[0]);
		clean_exit(shell, 127);
	}
	execve(path, cmd->argv, shell->env);
	perror("execve");
	free(path);
	clean_exit(shell, 126);
}

static void	run_single_child(t_shell *shell, t_cmd *cmd)
{
	setup_child_signals();
	if (!apply_redirections(cmd->redirs))
		exit(1);
	exec_external(cmd, shell);
}

static void	start_single_child(t_shell *shell, t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
		run_single_child(shell, cmd);
	wait_for_child(shell, pid);
}

void	execute_single_command(t_shell *shell, t_cmd *cmd)
{
	int		saved[2];

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return ;
	if (is_buildin(cmd->argv[0]))
	{
		run_saved_builtin(shell, cmd, saved);
		return ;
	}
	start_single_child(shell, cmd);
}
