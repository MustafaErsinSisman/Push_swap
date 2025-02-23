/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:56:46 by musisman          #+#    #+#             */
/*   Updated: 2025/02/23 19:51:49 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	t_list	*first;
	t_list	*last;

	if (!stacks || !stacks->stack_a || !stacks->stack_a->next)
		return ;
	first = stacks->stack_a;
	last = ft_lstlast(stacks->stack_a);
	last->next = first;
	stacks->stack_a = first->next;
	first->next = NULL;
}

void	rb(t_stacks *stacks)
{
	t_list	*first;
	t_list	*last;

	if (!stacks || !stacks->stack_b || !stacks->stack_b->next)
		return ;
	first = stacks->stack_b;
	last = ft_lstlast(stacks->stack_b);
	last->next = first;
	stacks->stack_b = first->next;
	first->next = NULL;
}

void	rr(t_stacks *stacks)
{
	if ((!stacks->stack_a || !stacks->stack_a->next)
		&& (!stacks->stack_b || !stacks->stack_b->next))
		return ;
	if (stacks->stack_a && stacks->stack_a->next)
		ra(stacks);
	if (stacks->stack_b && stacks->stack_b->next)
		rb(stacks);
}
