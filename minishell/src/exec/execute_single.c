#includes "../../includes/minishell.h"

static void	exec_external(t_cmd *cmd, char **envp)
{
	char *path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		exit(1);
	path = find_command_path(cmd->argv[0], envp);
	if (!path)
	{
		print_exec_error(cmd->argv[0], envp);
		exit(127);
	}
	execve(path, cmd->argv, envp);
	perror("execve");
	free(path);
	exit(126);
}

static void    execute_single_command(t_cmd *cmd, char **envp)
{
	pid_t pid;
	int	status;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return ;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		if (!apply_redirections(cmd->redirs))
			exit(1);
		if (!is_buildin(cmd->argv[0]))
			exit(execute_builtin(cmd, envp));
		exec_external(cmd, envp);
	}
	waitpid(pid, &status, 0);
}
