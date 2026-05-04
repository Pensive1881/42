/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:43:50 by acasper           #+#    #+#             */
/*   Updated: 2026/03/25 17:43:52 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_cmd	*parse_tokens(t_token *tokens)
{
	t_token	*cur;

	if (!tokens)
		return (NULL);
	cur = tokens;
	return (parse_pipeline(&cur));
}
