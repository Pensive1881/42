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

void	prompt_loop(t_shell *shell)
{
	char	*input;
	t_token	*tokens;
	t_cmd	*cmds;

	(void)envp;
	while (shell->running)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			write(1, "exit\n", 5);
			break;
		}

		if (*input)
			add_history(input);
<<<<<<< HEAD
		execute_command(input, envp);
=======

		tokens = lexer(input);
		if (!tokens)
		{
			free(input);
			continue;
		}

		if (!validate_syntax(tokens))
		{
			printf("syntax error\n");
			shell->last_status = 2;
			free_tokens(tokens);
			free(input);
			continue;
		}

		cmds = parse_tokens(tokens);
		if (!cmds)
		{
			shell->last_status = 2;
			free_tokens(tokens);
			free(input);
			continue;
		}

		execute_pipeline(shell, cmds);

		free_cmds(cmds);
<<<<<<< HEAD
		free_all(tokens);
>>>>>>> 268323ff0502d26e301205d266d7fde5af79e45c
=======
		free_tokens(tokens);
>>>>>>> 86e865053e2826b989fe1e235da89e2b9d0214bf
		free(input);
	}
}
