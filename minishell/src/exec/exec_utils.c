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
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
}

void	child_exec(t_shell *shell, t_cmd *cmd, int in_fd, int out_fd)
{
	char	*path;

	setup_child_signals();
	if (in_fd != -1 && in_fd != STDIN_FILENO)
	{
		if (dup2(in_fd, STDIN_FILENO) < 0)
		{
			free_env(shell->env);
			free_cmds(shell->cmds);
			free_tokens(shell->tokens);
			free(shell->input);
			perror("dup2");
			exit(1);
		}
	}
	if (out_fd != STDOUT_FILENO)
	{
		if (dup2(out_fd, STDOUT_FILENO) < 0)
		{
			free_env(shell->env);
			free_cmds(shell->cmds);
			free_tokens(shell->tokens);
			free(shell->input);
			perror("dup2");
			exit(1);
		}
	}
	close_fd_if_needed(in_fd);
	close_fd_if_needed(out_fd);
	if (!apply_redirections(cmd->redirs))
	{
		free_env(shell->env);
		free_cmds(shell->cmds);
		free_tokens(shell->tokens);
		free(shell->input);
		exit(1);
	}
	if (is_buildin(cmd->argv[0]))
	{
		shell->last_status = execute_buildin(shell, cmd);
		free_env(shell->env);
		free_cmds(shell->cmds);
		free_tokens(shell->tokens);
		free(shell->input);
		exit(shell->last_status);
	}
	path = find_command_path(cmd->argv[0], shell->env);
	if (!path)
	{
		print_exec_error(cmd->argv[0]);
		free_env(shell->env);
		free_cmds(shell->cmds);
		free_tokens(shell->tokens);
		free(shell->input);
		exit(127);
	}
	execve(path, cmd->argv, shell->env);
	perror("execve");
	free_env(shell->env);
	free_cmds(shell->cmds);
	free_tokens(shell->tokens);
	free(shell->input);
	free(path);
	exit(126);
}
