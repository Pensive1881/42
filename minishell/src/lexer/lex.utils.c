void	unclosed_quote(t_token *head)//almost sure this function is not needed
{
	t_token	*current;
	int	i;

	i = 0;
	current = head;
	if (current[i] == '"' || current[i] == '\'')
	{
		while (current[i] != '\0' || current[i] != '"' || current[i] != '\'')
			i++;
		if (current[i] == '\0' && (current[i] != '"' || current[i] != '\''))
	}
}//don't know about this fuction how usfull its gonna be. need to finish it aswell. 
 //the moto of this function was to return error if the quotes are not closed, 
 //but i did add a cheak in the quote function, if input[*i] reaches \0 means the 
 //quotes are not being closed so it returns NULL
 
void	free_all(t_token *head)
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

char	*expand_env(char *input, int *i)// will need to add env(char **env) variable later
{
	char	*head;

	if (input[*i] && input[1] == '$')
		(*i)++;
	while ()
}
