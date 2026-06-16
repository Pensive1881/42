#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

int	cd(char **av, int i)
{
	if (i != 2)
		return (error("error: cd: bad arguments\n"));
	if (chdir(av[1]) == -1)
	{
		ft_putstr_fd("error: cd: cannot change directory to ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}

void	fatal(void)
{
	error("error: fatal\n");
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd[2];
	int	tmp_fd;
	int	has_pipe;
	int	pid;
	int	status;
	int	ret;

	(void)ac;
	i = 0;
	ret = 0;
	tmp_fd = dup(0);
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i == 0)
			continue ;
		if (!strcmp(av[0], "cd"))
			ret = cd(av, i);
		else
		{
			has_pipe = (av[i] && !strcmp(av[i], "|"));

			if (has_pipe)
				if (pipe(fd) == -1)
					return (fatal(), 1);
			pid = fork();
			if (pid == -1)
				return (fatal(), 1);
			if (pid == 0)
			{
				av[i] = NULL;
				dup2(tmp_fd, 0);
				close(tmp_fd);
				if (has_pipe)
				{
					dup2(fd[1], 1);
					close(fd[0]);
					close(fd[1]);
				}
				execve(av[0], av, env);
				ft_putstr_fd("error: cannot execute ", 2);
				ft_putstr_fd(av[0], 2);
				ft_putstr_fd("\n", 2);
				return (1);
			}
			waitpid(pid, &status, 0);
			close(tmp_fd);

			if (has_pipe)
			{
				close(fd[1]);
				tmp_fd = fd[0];
			}
			else
				tmp_fd = dup(0);
			if (WIFEXITED(status))
				ret = WEXITSTATUS(status);
		}
	}
	close(tmp_fd);
	return (ret);
}
