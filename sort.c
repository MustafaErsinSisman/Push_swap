/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 05:28:35 by musisman          #+#    #+#             */
/*   Updated: 2025/02/15 05:28:35 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"
void is_sort(t_stacks *stacks)
{
    t_list *tmp;

    if (!stacks || !stacks->stack_a)
        return ;
    tmp = stacks->stack_a;
    if (!tmp->next)
    {
        free_stacks(stacks);
        exit(0);        
    }
    while (tmp->next)
    {
        if (*(int *)tmp->content > *(int *)tmp->next->content)
            return;
        tmp = tmp->next;
    }
    free_stacks(stacks);
    exit(0);
}

void is_two_node(t_stacks *stacks)
{
    if (stacks->count_a == 2)
    {
        if (stacks->stack_a && stacks->stack_a->next)
        {
            if (*(int *)stacks->stack_a->content > *(int *)stacks->stack_a->next->content)
            {
                actions(stacks, "sa");
                free_stacks(stacks);
                exit(0);
            }
        }
    }
}

void is_three_node(t_stacks *stacks)
{
    t_list *tmp;
    
    if (stacks->count_a == 3)
    {
        tmp = stacks->stack_a;
        if (*(int *)tmp->content > *(int *)tmp->next->content)
        {
            if (*(int *)tmp->content > *(int *)tmp->next->next->content)
                actions(stacks, "ra");
            else
                actions(stacks, "sa");
        }
        else
                actions(stacks, "rra");
        is_sort(stacks);
        actions(stacks, "sa");
        free_stacks(stacks);
        exit(0);
    }
}
void so_sort_time(t_stacks *stacks)
{
    int chose_number;

    actions(stacks, "pb");
    actions(stacks, "pb");
    while (ft_lstsize(stacks->stack_a) > 3)
    {
        chose_number = (stacks);
        chosen_number_actions(stacks, chose_number);
    }
    
    // hamle sayısı bul en az olan sayıyı bul
    // bulunan sayının uygun hamlelerini yap
}