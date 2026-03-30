# include "lexer.h"
# include "../../libft/includes/libft.h"
 
void	free_tokens(t_token *head)
{
	t_token	*current;
	t_token	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
}

char	*expand_var(char *input, int *i)// will need to add env(char **env) variable later
{
	char	*variable;
	char	*value;
	int	start;

	if (input[*i] == '$')
		(*i)++;
	start = *i;
	while (ft_isalnum(input[*i]) || input[*i] == '_')
		(*i)++;
	//how to extract variable names inside the quotes?
	variable = ft_substr(input, start, *i - start);
	value = getenv(variable);
	free(variable);
	return (value);
}
