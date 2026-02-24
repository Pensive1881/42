/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:35:19 by acasper           #+#    #+#             */
/*   Updated: 2026/01/15 18:37:20 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// parsing and validation
t_stack				*parse_args(int argc, char **argv);
int					is_valid_number(char *str);
int					has_duplicates(t_stack *stack);
int					is_sorted(t_stack *stack);
long				ft_atol(const char *str);

// stack operations
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b, int print);
void				pa(t_stack **a, t_stack **b, int print);
void				pb(t_stack **a, t_stack **b, int print);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b, int print);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b, int print);

// stack utils
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **stack, t_stack *new);
void				stack_add_front(t_stack **stack, t_stack *new);
int					stack_size(t_stack *stack);
t_stack				*stack_last(t_stack *stack);
void				free_stack(t_stack **stack);

// sorting algorithms
void				sort_three(t_stack **a);
void				sort_small(t_stack **a, t_stack **b);
void				sort_large(t_stack **a, t_stack **b);
void				index_stack(t_stack **stack);

// helper functions
int					get_min(t_stack *stack);
int					get_max(t_stack *stack);
int					get_position(t_stack *stack, int value);
void				error_exit(void);

#endif
