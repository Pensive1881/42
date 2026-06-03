/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:27:45 by acasper           #+#    #+#             */
/*   Updated: 2026/05/22 20:21:24 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/lexer.h"
#include "../includes/minishell.h"
#include "../includes/parser.h"

static int	handle_input(t_shell *shell, char *input)
{
	t_token	*tokens;
	t_cmd	*cmds;

	tokens = lexer(input, shell);
	if (!tokens)
		return (0);
	expand_tokens(tokens, shell);
	if (!validate_syntax(tokens))
	{
		printf("syntax error\n");
		shell->last_status = 2;
		return (free_tokens(tokens), 0);
	}
	cmds = parse_tokens(tokens);
	if (!cmds)
		return (shell->last_status = 2, free_tokens(tokens), 0);
	if (!prepare_heredocs(cmds))
		return (free_cmds(cmds), free_tokens(tokens), 0);
	shell->input = input;
	shell->tokens = tokens;
	shell->cmds = cmds;
	execute_pipeline(shell, cmds);
	return (free_cmds(cmds), free_tokens(tokens), 1);
}

void	prompt_loop(t_shell *shell)
{
	char	*input;

	while (shell->running)
	{
		g_signal = 0;
		input = readline("minishell$ ");
		if (!input)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (*input)
			add_history(input);
		handle_input(shell, input);
		free(input);
		if (shell->should_exit == 1)
			return (free_env(shell->env), exit(shell->last_status));
	}
}
