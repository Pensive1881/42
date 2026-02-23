/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:33:36 by acasper           #+#    #+#             */
/*   Updated: 2026/02/23 18:52:24 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_valid_number(char *str)
{
	long	num;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

static t_stack	*parse_single_arg(char *str)
{
	t_stack	*stack;
	char	**tokens;
	int		i;

	tokens = ft_split(str, ' ');
	if (!tokens)
		return (NULL);
	stack = NULL;
	i = 0;
	while (tokens[i])
	{
		if (!is_valid_number(tokens[i]))
		{
			free_stack(&stack);
			while (tokens[i])
				free(tokens[i++]);
			free(tokens);
			error_exit();
		}
		stack_add_back(&stack, stack_new((int)ft_atol(tokens[i])));
		free(tokens[i++]);
	}
	free(tokens);
	return (stack);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	if (argc == 2)
		stack = parse_single_arg(argv[1]);
	else
	{
		stack = NULL;
		i = 1;
		while (i < argc)
		{
			if (!is_valid_number(argv[i]))
			{
				free_stack(&stack);
				error_exit();
			}
			stack_add_back(&stack, stack_new((int)ft_atol(argv[i])));
			i++;
		}
	}
	if (has_duplicates(stack))
		(free_stack(&stack), error_exit());
	return (stack);
}
