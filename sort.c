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
int is_sort(t_list *stack)
{
    t_list *tmp;

    if (!stack)
        return (0);
    tmp = stack;
    if (!tmp->next)
        return (-1);
    while (tmp->next)
    {
        if (*(int *)tmp->content > *(int *)tmp->next->content)
            return (1);
        tmp = tmp->next;
    }
    tmp = stack;
    while (tmp->next)
    {
        if (*(int *)tmp->content < *(int *)tmp->next->content)
            return (-1);
        tmp = tmp->next;
    }
    return (0);
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
        is_sort(stacks->stack_a);
        actions(stacks, "sa");
        if (stacks->count_b == 0)
        {
            free_stacks(stacks);
            exit(0);
        }
    }
}
void so_sort_time(t_stacks *stacks)
{
    int chose_number;

    actions(stacks, "pb");
    actions(stacks, "pb");
    while (ft_lstsize(stacks->stack_a) > 3)
    {
        chose_number = chosen_number(stacks);
        chosen_number_actions(stacks, chose_number);
        actions(stacks, "pb");
    }
    if (!is_sort(stacks->stack_b))
    {
        // if count b %2 = 0 &&      if (count b / 2 < indis(max sayı))   (indis) kere rb         else (count b - indis) kere rrb 
        // else if count b %2 = 1 &&  if (count b / 2 <= indis(max sayı))  (indis) kere rb     else  (count b - indis) kere rrb
    }
    if (is_sort(stacks->stack_a))
        is_three_node(stacks);
    // sonra a'ya at
    write_stack(stacks);
}
