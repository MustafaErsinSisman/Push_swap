/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:46:09 by musisman          #+#    #+#             */
/*   Updated: 2025/02/23 20:27:27 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_list	*first;
	t_list	*second;

	if (!stacks || !stacks->stack_a || !(stacks->stack_a->next))
		return ;
	first = stacks->stack_a;
	second = stacks->stack_a->next;
	first->next = second->next;
	second->next = first;
	stacks->stack_a = second;
}

void	sb(t_stacks *stacks)
{
	t_list	*first;
	t_list	*second;

	if (!stacks || !stacks->stack_b || !(stacks->stack_b->next))
		return ;
	first = stacks->stack_b;
	second = stacks->stack_b->next;
	first->next = second->next;
	second->next = first;
	stacks->stack_b = second;
}

void	ss(t_stacks *stacks)
{
	if ((!stacks || !stacks->stack_a || !(stacks->stack_a->next))
		&& (!stacks || !stacks->stack_b || !(stacks->stack_b->next)))
		return ;
	sa(stacks);
	sb(stacks);
}

void	pa(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks->stack_b)
		return ;
	tmp = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	tmp->next = stacks->stack_a;
	stacks->stack_a = tmp;
	stacks->count_a++;
	stacks->count_b--;
}

void	pb(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks->stack_a)
		return ;
	tmp = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	tmp->next = stacks->stack_b;
	stacks->stack_b = tmp;
	stacks->count_a--;
	stacks->count_b++;
}
