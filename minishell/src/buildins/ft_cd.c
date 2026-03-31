# include "../../includes/minishell.h"

int	ft_cd(char **args, char **env)
{
	char	*home;
	char	*oldpwd;
	//so args[1] willbe the path to go
	//need to use chdir() to to enter the listed directry om args[1]
	//if no arguments, go to home?
	//if the given path is not correct, it need to print an error and return(1)
	//need to update PWD and OLDPWD?
	if (!args[1])
	{
		home = get_env_value(env, "HOME");
		if (!home)
			return (1);
		chdir(home);
	}
	else if (ft_strncmp(args[1], "-", 1) == 0)
	{
		oldpwd = get_env_value(env, "OLDPWD");
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
		{
		
		}
	}
}
