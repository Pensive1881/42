#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int	i;
	int	fd[2];
	int	in;
	int	status;
	int	ret;

	in = 0;
	ret = 0;
	i = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1)
			return (1);
		if (fork() == 0)
		{
			if (in)
			{
				dup2(in, 0);
				close(in);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				dup2(fd[1], 1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(fd[1]);
			in = fd[0];
		}
		i++;
	}
	while (wait(&status) > 0)
		if (!WIFEXITED(status) || WEXITSTATUS(status))
			ret = 1;
	return (ret);
}
