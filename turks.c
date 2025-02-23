/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:03:49 by musisman          #+#    #+#             */
/*   Updated: 2025/02/03 19:03:49 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void write_stack(t_stacks *stacks)
{
    t_list *tmp_a = stacks->stack_a;
    t_list *tmp_b = stacks->stack_b;

    ft_printf("\n ---------     ---------\n");
    ft_printf("| StackA: |   | StackB: |\n");
    ft_printf(" ---------     ---------\n");
    int max_count = (stacks->count_a > stacks->count_b) ? stacks->count_a : stacks->count_b;
    for (int i = 0; i < max_count; i++)
    {
        if (tmp_a)
        {
            ft_printf("|    %d    |", *(int *)(tmp_a->content));
            tmp_a = tmp_a->next;
        }
        else
            ft_printf("|         |");
        ft_printf("   ");
        if (tmp_b)
        {
            ft_printf("|    %d    |", *(int *)(tmp_b->content));
            tmp_b = tmp_b->next;
        }
        else
            ft_printf("|         |");
        ft_printf("\n");
    }
    ft_printf(" ---------     ---------\n");
}
int turk_algorithm(t_stacks *stacks)
{
    if (is_sort(stacks->stack_a) == -1)
    {
        free_stacks(stacks);
        exit(0);
    }
    is_two_node(stacks);
    is_three_node(stacks);
    so_sort_time(stacks);
    return  (1);
}
