/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:56:46 by musisman          #+#    #+#             */
/*   Updated: 2025/01/29 15:46:29 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_list **a)
{
        t_list *first;
        t_list *last;

        if (!a || !*a || !(*a)->next)
 		return ;

        first = *a;
        last = ft_lstlast(*a);
        
        last->next = first;
        *a = first->next;
        first->next = NULL;
}


void rb(t_list **b)
{
        t_list *first;
        t_list *last;

        if (!b || !*b || !(*b)->next)
 		return ;

        first = *b;
        last = ft_lstlast(*b);
        
        last->next = first;
        *b = first->next;
        first->next = NULL;
}


void rr(t_list **a, t_list **b)
{
        ra(a);
        rb(b);
}