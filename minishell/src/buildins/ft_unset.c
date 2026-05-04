# include "../../includes/minishell.h"

int	ft_unset(char **args, t_shell *shell)
{
	int	i;
	int	j;
	int	len;

	if (!*args)
		return (0);
	i = 1;
	len  = ft_strlen(args[i]);
	while (args[i])
	{
		j = 0;
		while (shell->env[j])
		{
			if (ft_strncmp(shell->env[j], args[i], len) == 0 && shell->env[j][len] == '=')
			{//after finding the var, it has to be deleted and 
			 //the other vars has to be pulled a step back after removing the one
				while (shell->env[j + 1])
				{
					shell->env[j] = shell->env[j + 1];
					j++;
				}
				shell->env[j] = NULL;//after updating the arry the last value being set to NULL
				break ; //once the var is being removed the programm can be stop 
			}
			j++;
		}
		i++;
	}
	return (0);
}
