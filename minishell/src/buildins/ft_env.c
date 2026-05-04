# include "../../includes/minishell.h"

int	ft_env(t_shell *shell)
{
	int	i;

	i = 0;
	if (!shell->env)
		return (1);
	while (shell->env[i])
	{
		ft_putendl_fd(shell->env[i], i);
		i++;
	}
	return (0);
}
