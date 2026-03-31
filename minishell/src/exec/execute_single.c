#includes "../../includes/minishell.h"

static void	exec_external(t_cmd *cmd, char **envp)
{
	char *path;

	path = find_command_path(cmd->argv[0], envp);

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
        if (pid == 0)
        {
                execve(cmd->argv[0], cmd->argv, envp);
                perror("execve");
                exit(EXIT_FAILURE);
		exec_external(cmd, envp);
        }
        waitpid(pid, &status, 0);
}
