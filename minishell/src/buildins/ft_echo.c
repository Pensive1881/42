# include "../../includes/minishell.h"

int	ft_echo(char **args)
{
	int	i;
	int	no_newline; // flag to mark if new line should be printed

	i = 0;
	no_newline = 0;
	if (args[0] == "echo")
		i++;
	if (args[1] == "-n")
	{
		no_newline = 1;
		i++;
	}
	while (args[i])
	{
		
	}
	
	return (0);
}
