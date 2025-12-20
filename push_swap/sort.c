/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 by acasper                   #+#    #+#             */
/*   Updated: 2025/12/20 by acasper                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = *stack;
	while (current)
	{
		index = 0;
		compare = *stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (stack_size(*a) != 3)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;
	int	min;
	int	pos;

	size = stack_size(*a);
	while (size > 3)
	{
		min = get_min(*a);
		pos = get_position(*a, min);
		if (pos <= size / 2)
		{
			while ((*a)->value != min)
				ra(a, 1);
		}
		else
		{
			while ((*a)->value != min)
				rra(a, 1);
		}
		pb(a, b, 1);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b, 1);
}

void	sort_large(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, 1);
			else
				ra(a, 1);
			j++;
		}
		while (*b)
			pa(a, b, 1);
		i++;
	}
}
