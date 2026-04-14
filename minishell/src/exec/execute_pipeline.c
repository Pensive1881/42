/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:45:07 by acasper           #+#    #+#             */
/*   Updated: 2026/03/25 17:45:09 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	execute_pipeline(t_shell *shell, t_cmd *cmds)
{
	if (!cmds)
		return ;
	if (!cmds->next)
		execute_single_command(shell, cmds);
	else
		execute_multi_command(shell, cmds);
}
