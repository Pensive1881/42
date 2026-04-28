int	execute_buildin(char	**args, t_shell *shell)// need to move this to exec_utils.c
{
	if (ft_strncmp(args[0], "cd", 2) == 0)
		return (ft_cd(args, shell));
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
		return (ft_pwd());
	else if (ft_strncmp(args[0], "echo", 4) == 0)
		return (ft_echo(args));
	else if (ft_strncmp(args[0], "env", 3) == 0)
		return (ft_env(shell));
	else if (ft_strncmp(args[0], "exit", 4) == 0)
		return (ft_exit(args, shell));
	else if (ft_strncmp(args[0], "unset", 5) == 0)
		return (ft_unset(args, shell));
	else if (ft_strncmp(args[0], "export", 6) == 0)
		return (ft_export(args, shell));
	return (-1);
}
