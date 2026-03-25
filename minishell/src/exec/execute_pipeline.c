/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:45:07 by acasper           #+#    #+#             */
/*   Updated: 2026/03/25 17:45:09 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	execute_pipeline(t_cmd *cmds, char **envp)
{
	if (!cmds || cmds->next)
		return ;
	execute_single_command(cmds, envp);
}

void	execute_single_command(t_cmd *cmd, char **envp)
{
	pid_t pid;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return ;
	pid = fork();
	if (pid == 0)
	{
		execve(cmd->argv[0], cmd->argv, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
}
