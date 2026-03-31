/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:00:43 by acasper           #+#    #+#             */
/*   Updated: 2026/03/31 21:00:50 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	is_builtin(char *cmd)
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

int	exedute_builtin(t_cmd *cmd, char **envp)
{
	(void)cmd;
	(void)envp;
	ft_putendl_fd("builtin execution hook not connected yet", 2);
	return (0);
}

void	close_fd_if_needede(int fd)
{
	if (fd >= 0 && fd != STDIN_FILEO && fd != STDOUT_FILEO)
		close(fd);
}

void	print_exec_error(char *cmd)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
}

void	child_exec(t_cmd *cmd, int in_fd, int out_fd, char **envp)
{
	char *path;

	if (in_fd != -1 && in_fd != STDIN_FILEO)
	{
		if (dup2(in_fd, STDIN_FILEO) < 0)
			return (perror("dup2"), exit(1));
	}
	if (out_fd != STDOUT_FILEO)
	{
		if (dup2(out_fd, STDOUT_FILEO) < 0)
			return (perror("dup2"), exit(1));
	}
	close_fd_if_needed(in_fd);
	close_fd_if_needed(out_fd);
	if (!apply_redirections(cmd->redirs))
		exit(1);
	if (is_builtin(cmd->argv[0]))
		exit(execute_builtin(cmd, envp));
	path = find_command_path(cmd->argv[0], envp);
	if (!path)
	{
		print_exec_error(cmd->argv[0]);
		exit(127);
	}
	execve(path, cmd->argv, envp);
	perror("execve");
	free(path);
	exit(126);
}
