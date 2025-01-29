/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:46:09 by musisman          #+#    #+#             */
/*   Updated: 2025/01/29 14:50:11 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **a)
{
	t_list *first;
	t_list *second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;

	first->next = second->next;
	second->next = first;
	*a = second;
}

void sb(t_list **b)
{
	t_list *first;
	t_list *second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;

	first->next = second->next;
	second->next = first;
	*b = second;
}

void ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
