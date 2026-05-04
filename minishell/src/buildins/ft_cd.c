# include "../../includes/minishell.h"

int	ft_cd(char **args, t_shell *shell)
{
	char	*home;
	char	*oldpwd;
	char	*newpwd;
	//so args[1] willbe the path to go
	//need to use chdir() to to enter the listed directry om args[1]
	//if no arguments, go to home?
	//if the given path is not correct, it need to print an error and return(1)
	//need to update PWD and OLDPWD?
	if (!args[1])
	{
		home = get_env_value(shell->env, "HOME");
		if (!home)
			return (1);
		chdir(home);
	}
	else if (ft_strncmp(args[1], "-", 1) == 0)
	{
		oldpwd = get_env_value(shell->env, "OLDPWD");
		if (!oldpwd)
		{
			ft_putendl_fd("Error: OLDPWD not set", 2);
			return (1);
		}
		chdir(oldpwd);
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			ft_putendl_fd("Error: no uch file or directory", 2);
			return (1);
		}
		else
		{//the current pwd has to saved first as old
		 	oldpwd = get_env_value(shell->env, "PWD");
			update_env(shell->env, "OLDPWD", oldpwd);
			chdir(args[1]);
			newpwd = getcwd(NULL, 0);
			update_env(shell->env, "PWD", newpwd);
			free(newpwd);
		}
	}
	return (0);
}
