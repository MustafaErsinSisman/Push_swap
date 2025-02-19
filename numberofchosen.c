/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberofchosen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:35:58 by musisman          #+#    #+#             */
/*   Updated: 2025/02/18 22:35:58 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int chose_number_b(t_stacks *stacks, int a_number)
{
        int num_b;
        t_list *b_stack;

        num_b = -2147483648;
        b_stack = stacks->stack_b;
        while (b_stack->next)
        {
                if ((a_number > *(int *)b_stack->content) && num_b < *(int *)b_stack->content)
                        num_b = *(int *)b_stack->content;
                b_stack = b_stack->next;
        }
        b_stack = stacks->stack_b;
        if (num_b == -2147483648)
        {
                while (b_stack)
                {
                        if (num_b < *(int *)b_stack->content)
                                num_b = *(int *)b_stack->content;
                        b_stack = b_stack->next;
                }
        }
        return (num_b);
}

int	move_number(t_stacks *stacks, int index_a, int index_b)
{		
	if (stacks->count_a / 2 >= index_a && stacks->count_b / 2 >= index_b) //+ +
	{
		if (index_a > index_b)
			return (index_a);
		return (index_b);
	}
	else if (stacks->count_a / 2 <= index_a && stacks->count_b / 2 >= index_b) //- +
		return (stacks->count_a - index_a + index_b);
	else if (stacks->count_a / 2 >= index_a && stacks->count_b / 2 <= index_b)//+ -
		return (stacks->count_b - index_b + index_a);
	else if (stacks->count_a / 2 <= index_a && stacks->count_b / 2 <= index_b) //- -
	{
		if (index_a > index_b)
			return (stacks->count_a - index_a);
		return (stacks->count_b - index_b);
	}
	return (0);
}

int chosen_index(t_stacks *stacks, int chose_move, int chose_index)
{
        t_list *a_stack;
        int index_a;
        int index_b;
        int num_b;
        int move;

        a_stack = stacks->stack_a;
        while (a_stack)
        {
                printf("kontrol sayı: %d\n\n", *(int *)a_stack->content);
                num_b = chose_number_b(stacks, *(int *)a_stack->content);
                printf("num_b: %d\n", num_b);
                index_a = pos(stacks->stack_a, *(int *)a_stack->content);
                printf("indexa: %d\n", index_a);
                index_b = pos(stacks->stack_b, num_b);
                printf("indexb: %d\n", index_b);
                move = move_number(stacks, index_a, index_b);
                printf("move: %d\n", move);
                if (move < chose_move && index_a < chose_index)
                {
                        chose_index = index_a;
                        chose_move = move;
                }
                printf("chose index:%d\n", chose_index);
                printf("chose move:%d\n", chose_move);
                a_stack = a_stack->next;
                printf("\n");
        }
        printf("\n");
        return (chose_index);
}

int chosen_number(t_stacks *stacks)
{
        t_list *a_stack;
        int pos;
        int chose_number;

        pos = 0;
        chose_number = -2147483648;
        a_stack = stacks->stack_a;
        while (a_stack->next)
        {
                printf("pos in chosen number: %d\n\n", pos);
                if (pos == chosen_index(stacks, 2147483647, 0))
                {
                        chose_number = *(int *)a_stack->content;
                        break ;
                }
                pos++;
                a_stack = a_stack->next;
        }
        return (chose_number);
}

void chosen_number_actions(t_stacks *stacks, int chose_number)
{
        printf("%d\n", chose_number);
        write_stack(stacks);
}