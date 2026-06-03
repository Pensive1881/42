/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:00:43 by acasper           #+#    #+#             */
/*   Updated: 2026/05/25 18:19:22 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	is_buildin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	return (0);
}

int	execute_buildin(t_shell *shell, t_cmd *cmd)
{
	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (1);
	if (ft_strncmp(cmd->argv[0], "echo", 5) == 0)
		return (ft_echo(cmd->argv));
	if (ft_strncmp(cmd->argv[0], "pwd", 4) == 0)
		return (ft_pwd());
	if (ft_strncmp(cmd->argv[0], "env", 4) == 0)
		return (ft_env(shell));
	if (ft_strncmp(cmd->argv[0], "cd", 3) == 0)
		return (ft_cd(cmd->argv, shell));
	if (ft_strncmp(cmd->argv[0], "export", 7) == 0)
		return (ft_export(cmd->argv, shell));
	if (ft_strncmp(cmd->argv[0], "unset", 6) == 0)
		return (ft_unset(cmd->argv, shell));
	if (ft_strncmp(cmd->argv[0], "exit", 5) == 0)
		return (ft_exit(cmd->argv, shell));
	return (1);
}

void	close_fd_if_needed(int fd)
{
	if (fd >= 0 && fd != STDIN_FILENO && fd != STDOUT_FILENO)
		close(fd);
}

void	print_exec_error(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found", 2);
}

void	child_exec(t_shell *shell, t_cmd *cmd, int in_fd, int out_fd)
{
	setup_child_signals();
	dup_child_fds(shell, in_fd, out_fd);
	close_fd_if_needed(in_fd);
	close_fd_if_needed(out_fd);
	if (!apply_redirections(cmd->redirs))
		clean_exit(shell, 1);
	if (is_buildin(cmd->argv[0]))
		exit_child_builtin(shell, cmd);
	exec_child_external(shell, cmd);
}
