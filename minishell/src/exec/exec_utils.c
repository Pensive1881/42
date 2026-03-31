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

	if ()
	{
		
	}
	
	free(path);
	exit(126);
}
