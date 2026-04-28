# include "../../includes/minishell.h"

int	ft_exit(char **args)
{
	int	num;

	if (!args)
	{
		exit(0);
	}
	if (args[2])
	{
		printf("%\n, Error: too many arguments");
		return (1);
	}
	else if (args[1])
	{
		if (!ft_isdigit(args[1]))
		{
			printf("%\n, Error: numeric value required");
			exit (1);
		}
		else
		{
			num = ft_atoi(args[1]);
			exit(num);
		}
	}
	return (0);
}
