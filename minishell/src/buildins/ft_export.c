#include "../../includes/minishell.h"

int	ft_export(char **args, char **env)
{
	int	i;
	char	*name;
	char	*value;
	char	*equal;

	i = 0;
	equal = ft_strchr(env[i], '=');
	if (!env)
		return (1);
	if (!args[1])
	{//if no args, it prints all the env vars? 
		ft_putstr_fd("declare -x", 1);
		write(1, env[i], equal - env[i] + 1);
		write(1, "\"", 1);
		ft_putstr_fd(equal + 1, 1);
		write(1, "\"", 1);
		write(1, "\n", 1);
		i++;
	}
	while (args[i])
	{
		
	}


}
