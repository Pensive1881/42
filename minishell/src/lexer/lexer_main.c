# include "lexer.h"
# include <stdio.h>

int	main(void)
{
	t_token	*token;
	int count = 0;
	
	printf("start\n");
	token = lexer("echo $HOME | cat > text.txt");
	t_token *current = token;
	while (current && count < 10)
	{
		printf("type: %d value: %s\n", current->type, current->value);
		current = current->next;
		count++;
	}
	free_tokens (token);
	return (0);
}
