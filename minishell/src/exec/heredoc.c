/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:51:12 by acasper           #+#    #+#             */
/*   Updated: 2026/05/22 20:07:27 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	write_heredoc_to_file(char *delimiter, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("open"), 0);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	return (1);
}

static int	replace_heredoc_redir(t_redir *redir, int *index)
{
	char	*tmp_name;
	char	*num;

	num = ft_itoa((*index)++);
	if (!num)
		return (0);
	tmp_name = ft_strjoin("/tmp/minishell_hd_", num);
	free(num);
	if (!tmp_name)
		return (0);
	if (!write_heredoc_to_file(redir->file, tmp_name))
		return (free(tmp_name), 0);
	free(redir->file);
	redir->file = tmp_name;
	redir->type = R_IN;
	return (1);
}

static int	prepare_cmd_heredocs(t_cmd *cmd, int *index)
{
	t_redir	*redir;

	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == R_HEREDOC)
		{
			if (!replace_heredoc_redir(redir, index))
				return (0);
		}
		redir = redir->next;
	}
	return (1);
}

int	prepare_heredocs(t_cmd *cmds)
{
	int	index;

	index = 0;
	while (cmds)
	{
		if (!prepare_cmd_heredocs(cmds, &index))
			return (0);
		cmds = cmds->next;
	}
	return (1);
}
