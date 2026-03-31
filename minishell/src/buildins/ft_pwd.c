# include "../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*cwd;

	getcwd(NULL,0);
	cwd = malloc...;
	if (!cwd)
		return (NULL); // might need to give an error message
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
