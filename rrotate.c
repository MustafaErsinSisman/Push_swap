/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:56:31 by musisman          #+#    #+#             */
/*   Updated: 2025/02/03 17:15:29 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	t_list	*first;
	t_list	*last;
	t_list	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = ft_lstlast(*a);
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last->next = first;
	*a = last;
	tmp->next = NULL;
}

void	rrb(t_list **b)
{
	t_list	*first;
	t_list	*last;
	t_list	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = ft_lstlast(*b);
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	last->next = first;
	*b = last;
	tmp->next = NULL;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
