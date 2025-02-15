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
    // Eğer stack A'nın uzunluğu 2 ise
    if (stacks->count_a == 2)
    {
        // stack A boş değilse ve stack A'nın bir sonraki elemanı varsa
        if (stacks->stack_a && stacks->stack_a->next)
        {
            // Eğer ilk eleman ikinci elemandan büyükse, sa işlemi yap
            if (*(int *)stacks->stack_a->content > *(int *)stacks->stack_a->next->content)
            {
                actions(stacks, "sa");
                write_stack(stacks);
                free_stacks(stacks);
                exit(0);
            }
        }
    }
}

void is_three_node(t_stacks *stacks)
{
        write_stack(stacks);
}
void so_sort_time(t_stacks *stacks)
{
        write_stack(stacks);
}