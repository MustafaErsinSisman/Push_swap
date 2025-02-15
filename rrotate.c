/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:56:31 by musisman          #+#    #+#             */
/*   Updated: 2025/02/15 05:19:00 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	t_list	*first;
	t_list	*last;
	t_list	*tmp;

	if (!stacks->stack_a || !(stacks->stack_a)->next)
		return ;
	first = stacks->stack_a;
	last = ft_lstlast(stacks->stack_a);
	tmp = stacks->stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = first;
	stacks->stack_a = last;
}

void	rrb(t_stacks *stacks)
{
	t_list	*first;
	t_list	*last;
	t_list	*tmp;

	if (!stacks->stack_b || !(stacks->stack_b)->next)
		return ;
	first = stacks->stack_b;
	last = ft_lstlast(stacks->stack_b);
	tmp = stacks->stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = first;
	stacks->stack_b = last;
}

void	rrr(t_stacks *stacks)
{
	if (stacks->stack_a && stacks->stack_a->next)
		rra(stacks);
	if (stacks->stack_b && stacks->stack_b->next)
		rrb(stacks);
}
