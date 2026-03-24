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
#include "minishell.h"
#include "../includes/lexer.h"
#include "../includes/parser.h"

void	prompt_loop(char **envp)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break;

		if (*input)
			add_history(input);

		free(input);
	}
}

static void	print_cmds(t_cmd *cmd)
{
	int	i;
	t_redir	*r;

	while (cmds)
	{
		printf("CMD:\n");
		i = 0;
		while (cmds->argv && cmds->argv[i])
		{
			printf("  argv[%d] = [%s]\n", i, cmds->argv[i]);
			i++;
		}
		r = cmds->redirs;
		while (r)
		{
			printf("  redir type=%d file=[%s]\n", r->type, r->file);
			r = r->next;
		}
		cmds = cmds->next;
		if (cmds)
			printf("PIPE ->\n");
	}
}

