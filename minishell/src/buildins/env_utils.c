# include "../../includes/minishell.h"

// the function to get env value
char	*get_env_value(char **env, char *key)
{
	int	i;
	int	len;
	// the length of the key e.g. HOME is needed to check what comes next
	i = 0;
	len = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')// now the key will be skiped
			return (env[i] + len + 1);// we skip the key and get what is afterwards
		i++;
	}
	return (NULL);
}

// the function to update env
int	update_env(char **env, char *key, char *value)
{
	int	i;
	int	len;
	char	*new_entry;
	char	*temp;

	i = 0;
	len = ft_strlen(key);
	temp = ft_strjoin(key, "=");// use temp for mem safety
	new_entry = ft_strjoin(temp, value);
	free(temp); // temp has to be freed rightaway 
	while (env[i])
	{// need to find the entry which starts with pwd
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
		{
			env[i] = new_entry;//must replace the old path with the new path
			return (0);
		}
		i++;
	}
	free(new_entry);//if it not found we need to free it
	return (1);//nothing updated
}

char	**cpy_env(char **env)// the function copy the env vars and funtions e.g. unset 
{ // will modify the copy not the original
	int	i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);	
}
