/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:27:45 by acasper           #+#    #+#             */
/*   Updated: 2026/03/04 17:52:17 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"
#include "../includes/lexer.h"
#include "../includes/parser.h"

void	prompt_loop(char **envp)
{
	char	*input;
	t_token	*tokens;
	t_cmd	*cmds;

	(void)envp;
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break;

		if (*input)
			add_history(input);

		tokens = lexer(input);
		if (!tokens)
		{
			free(input);
			continue;
		}

		if (!validate_syntax(tokens))
		{
			printf("syntax error\n");
			free_tokens(tokens);
			free(input);
			continue;
		}

		cmds = parse_tokens(tokens);
		if (!cmds)
		{
			free_tokens(tokens);
			free(input);
			continue;
		}

		execute_pipeline(cmds, envp);

		free_cmds(cmds);
		free_tokens(tokens);
		free(input);
	}
}
