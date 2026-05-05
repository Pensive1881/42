# include "lexer.h"
# include "minishell.h"
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

char	*expand_var(char *input, int *i, t_shell *shell)
{
	char	*variable;
	char	*value;
	int	start;

	if (input[*i] == '$')
		(*i)++;
	if (input[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(shell->last_status));
	}
	if (!input[*i] || (!ft_isalnum(input[*i]) && input[*i] != '_'))
		return (ft_strdup("$"));
	start = *i;
	while (ft_isalnum(input[*i]) || input[*i] == '_')
		(*i)++;
	//how to extract variable names inside the quotes?
	variable = ft_substr(input, start, *i - start);
	value = get_env_value(shell->env, variable);
	free(variable);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}
