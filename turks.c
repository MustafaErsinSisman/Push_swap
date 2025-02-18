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


// int get_position_in_a(t_list *a, int value)
// {
//     int pos = 0;
//     while (a)
//     {
//         if (*(int *)(a->content) == value)
//             return pos;
//         a = a->next;
//         pos++;
//     }
//     return -1;
// }

// int get_position_in_b(t_list *b, int value)
// {
//     int pos = 0;
//     int best_match = -1;
//     int best_match_pos = 0;
//     t_list *tmp = b;

//     while (tmp)
//     {
//         int b_value = *(int *)(tmp->content);
//         if (b_value > value)
//         {
//             if (best_match == -1 || b_value < best_match)
//             {
//                 best_match = b_value;
//                 best_match_pos = pos;
//             }
//         }
//         tmp = tmp->next;
//         pos++;
//     }

//     if (best_match == -1)
//     {
//         int max_pos = 0;
//         int max_value = INT_MIN;
//         pos = 0;
//         tmp = b;
//         while (tmp)
//         {
//             if (*(int *)(tmp->content) > max_value)
//             {
//                 max_value = *(int *)(tmp->content);
//                 max_pos = pos;
//             }
//             tmp = tmp->next;
//             pos++;
//         }
//         return max_pos + 1;
//     }
//     return best_match_pos;
// }

// int action_number(t_list *a, t_list *b)
// {
//     t_stacks actions;
//     t_list *tmp = a;
//     int min_moves = INT_MAX;
//     int best_value = 0;

//     actions.stack_a = a;
//     actions.stack_b = b;
//     actions.count_a = ft_lstsize(a);
//     actions.count_b = ft_lstsize(b);

//     while (tmp)
//     {
//         int value = *(int *)(tmp->content);
//         int index_a = get_position_in_a(a, value);
//         int index_b = get_position_in_b(b, value);

//         actions.ra = index_a;
//         actions.rra = actions.count_a - index_a;
//         actions.rb = index_b;
//         actions.rrb = actions.count_b - index_b;

//         actions.rr = fmin(actions.ra, actions.rb);
//         actions.ra -= actions.rr;
//         actions.rb -= actions.rr;

//         actions.rrr = fmin(actions.rra, actions.rrb);
//         actions.rra -= actions.rrr;
//         actions.rrb -= actions.rrr;

//         int total_moves = actions.ra + actions.rb + actions.rr + actions.rra + actions.rrb + actions.rrr;

//         if (total_moves < min_moves)
//         {
//             min_moves = total_moves;
//             best_value = value;
//         }
//         tmp = tmp->next;
//     }

//     ft_printf("En az hamlede taşınacak eleman: %d\n", best_value);
//     ft_printf("Hamleler: RA: %d, RB: %d, RR: %d, RRA: %d, RRB: %d, RRR: %d\n", 
//             actions.ra, actions.rb, actions.rr, actions.rra, actions.rrb, actions.rrr);
    
//     return min_moves;
// }


int turk_algorithm(t_stacks *stacks)
{
    is_sort(stacks);
    is_two_node(stacks);
    is_three_node(stacks);
    so_sort_time(stacks);
    write_stack(stacks);
    return  (1);
}
