# include "../../includes/minishell.h"

int	ft_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (1);
	while (env[i])
	{
		ft_putendl_fd(env[i], i);
		i++;
	}
	return (0);
}
