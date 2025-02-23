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
    int min_to_max = 1;
    int max_to_min = 1;

    if (!stack || !stack->next)
        return (-1);
    tmp = stack;
    while (tmp->next)
    {
        if (*(int *)tmp->content > *(int *)tmp->next->content)
            min_to_max = 0;
        if (*(int *)tmp->content < *(int *)tmp->next->content)
            max_to_min = 0;
        tmp = tmp->next;
    }
    if (max_to_min)
        return (1);
    if (min_to_max)
        return (-1);
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
        if (!is_sort(stacks->stack_a))
            actions(stacks, "sa");
        if (stacks->count_b == 0)
        {
            free_stacks(stacks);
            exit(0);
        }
    }
}

void sort_b(t_stacks *stacks)
{
    int max_indis;
    int rev_moves;

    if (is_sort(stacks->stack_b) != 1)
    {
        max_indis = pos(stacks->stack_b, chose_number_b(stacks, -2147483648));

        if (max_indis <= stacks->count_b / 2) 
        {
            while (max_indis-- > 0)
                actions(stacks, "rb");
        }
        else
        {
            rev_moves = stacks->count_b - max_indis;
            while (rev_moves-- > 0)
                actions(stacks, "rrb");
        }
    }
}















int find_min_in_a(t_list *stack_a)
{
    t_list *tmp = stack_a;
    int min_value = *(int *)stack_a->content;
    int min_pos = 0;
    int pos = 0;

    while (tmp)
    {
        if (*(int *)tmp->content < min_value)
        {
            min_value = *(int *)tmp->content;
            min_pos = pos;
        }
        pos++;
        tmp = tmp->next;
    }
    return min_pos;
}



void sort_a(t_stacks *stacks)
{
    int min_pos = find_min_in_a(stacks->stack_a);
    int half = stacks->count_a / 2;

    if (is_sort(stacks->stack_a) != -1)
    {
        if (min_pos <= half)
        {
            while (min_pos-- > 0)
                actions(stacks, "ra");
        }
        else
        {
            min_pos = stacks->count_a - min_pos;
            while (min_pos-- > 0)
                actions(stacks, "rra");
        }
    }
}





int find_position_in_a(t_list *stack_a, int number)
{
    t_list *tmp = stack_a;
    int pos = 0;
    int min_pos = 0;
    int min_value = *(int *)stack_a->content;

    while (tmp)
    {
        int curr_value = *(int *)tmp->content;
        if (curr_value > number && (min_value < number || curr_value < min_value))
        {
            min_value = curr_value;
            min_pos = pos;
        }
        pos++;
        tmp = tmp->next;
    }
    return min_pos;
}

void rotate_a(t_stacks *stacks, int pos)
{
    int half = stacks->count_a / 2;

    if (pos <= half)
    {
        while (pos-- > 0)
            actions(stacks, "ra");
    }
    else
    {
        pos = stacks->count_a - pos;
        while (pos-- > 0)
            actions(stacks, "rra");
    }
}

void move_b_to_a(t_stacks *stacks)
{
    int number;
    int pos;

    while (stacks->stack_b)
    {
        number = *(int *)stacks->stack_b->content;
        pos = find_position_in_a(stacks->stack_a, number);
        rotate_a(stacks, pos);
        actions(stacks, "pa");
    }
}















void so_sort_time(t_stacks *stacks)
{
    int chose_number;

    actions(stacks, "pb");
    if (stacks->count_a > 4)
        actions(stacks, "pb");
    while (ft_lstsize(stacks->stack_a) > 3) // 3 olacak dikkat
    {
        chose_number = chosen_number(stacks);
        chosen_number_actions(stacks, chose_number);
        actions(stacks, "pb");
        // printf("--------- chosen number: %d --------\n", chose_number);
    }
    // write'ları silip diğerlerini aç

    // write_stack(stacks);
    sort_b(stacks);
    // write_stack(stacks);
    if (is_sort(stacks->stack_a) != -1)
        is_three_node(stacks);
    // write_stack(stacks);
    move_b_to_a(stacks);
    // write_stack(stacks);
    sort_a(stacks);
    // write_stack(stacks);
}
