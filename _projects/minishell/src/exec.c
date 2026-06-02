/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:28:08 by acasper           #+#    #+#             */
/*   Updated: 2026/05/12 16:24:59 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	execute_command(char *input, char **envp)
{
	pid_t	pid;
	char	**args;

	args = split_args(input);
	if (!args || !args[0])
	{
		free_args(args);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
	free_args(args);
}
