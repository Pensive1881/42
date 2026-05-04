#include"../includes/minishell.h"
#include"../includes/lexer.h"

char	*expend_value(char *str, t_shell *shell)
{
	int	i;
	int	start;
	char	*result;
	char	*value;
	char	*temp;

	i = 0;
	result = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$')
		{
			value = expand_var(str, &i, shell);
			char	*old_value = value;
			result = ft_strjoin(result, value);
			free(old_value);	
		}
		else
		{
			start = i;
			while (str[i] != '$' || str[i] != '\0')
				i++;
			temp = ft_substr(str, start, i - start);
			old_result = result;
			result = ft_strjoin(result, temp);
			free(old_result);
			free(temp);
		}
	}
	return (result);
}

t_token	expand_tokens(t_token *tokens, t_shell *shell)
{
	t_token	*current;
	char	*old;

	current = tokens;
	while (current)
	{
		if (current->type == TOKEN_WORD && current->quote == '\'')
		{
			old = current->value;
			current->value = expand_value(current->value, shell);
			free(old);
		}
		current = current->next;
	}
	return (tokens);
}

