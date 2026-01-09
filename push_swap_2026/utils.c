/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:30:56 by acasper           #+#    #+#             */
/*   Updated: 2026/01/09 16:06:54 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6)
	exit(1);
}

void	free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack)
		return 0;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	get_min(t_stack *stack)
{
	
}

int get_max(t_stack *stack)
{
	
}

int get_position(t_stack *stack, int value)
{
	
}
