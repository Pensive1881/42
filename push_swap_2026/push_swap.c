/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:45:46 by acasper           #+#    #+#             */
/*   Updated: 2026/01/13 17:10:24 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void choose_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
	{
		index_stack(a);
		sort_large(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	a = parse_args(Argc, argv);
	if (!a)
		error_exit();
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	b = NULL;
	choose_sort(&a, &b);
	free_stack(&a);
	free_Stack(&b);
	return (0);
}
