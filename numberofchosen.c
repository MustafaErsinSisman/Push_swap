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

int	chose_number_b(t_stacks *stacks, int a_number)
{
	int		num_b;
	int		now_b;
	t_list	*b_stack;

	num_b = -2147483648;
	b_stack = stacks->stack_b;
	while (b_stack)
	{
		now_b = *(int *)b_stack->content;
		if ((a_number > now_b) && num_b < now_b)
			num_b = now_b;
		b_stack = b_stack->next;
	}
	b_stack = stacks->stack_b;
	if (num_b == -2147483648)
	{
		while (b_stack)
		{
			now_b = *(int *)b_stack->content;
			if (num_b < now_b)
				num_b = *(int *)b_stack->content;
			b_stack = b_stack->next;
		}
	}
	return (num_b);
}

int	chosen_index(t_stacks *stacks, int chose_move, int chose_index)
{
	t_list	*a_stack;
	int		index_a;
	int		index_b;
	int		num_b;
	int		move;

	a_stack = stacks->stack_a;
	while (a_stack)
	{
		num_b = chose_number_b(stacks, *(int *)a_stack->content);
		index_a = pos(stacks->stack_a, *(int *)a_stack->content);
		index_b = pos(stacks->stack_b, num_b);
		move = move_number(stacks, index_a, index_b);
		if (move < chose_move)
		{
			chose_index = index_a;
			chose_move = move;
		}
		a_stack = a_stack->next;
	}
	return (chose_index);
}

int	chosen_number(t_stacks *stacks)
{
	t_list	*a_stack;
	int		pos;
	int		chose_number;
	int		index;

	pos = 0;
	index = chosen_index(stacks, 5500, 500);
	chose_number = -2147483648;
	a_stack = stacks->stack_a;
	while (a_stack)
	{
		if (pos == index)
		{
			chose_number = *(int *)a_stack->content;
			break ;
		}
		pos++;
		a_stack = a_stack->next;
	}
	return (chose_number);
}

void	do_action(t_stacks *stacks)
{
	int	j;

	j = 0;
	while (j++ < stacks->rr)
		actions(stacks, "rr");
	j = 0;
	while (j++ < stacks->ra)
		actions(stacks, "ra");
	j = 0;
	while (j++ < stacks->rb)
		actions(stacks, "rb");
	j = 0;
	while (j++ < stacks->rrr)
		actions(stacks, "rrr");
	j = 0;
	while (j++ < stacks->rra)
		actions(stacks, "rra");
	j = 0;
	while (j++ < stacks->rrb)
		actions(stacks, "rrb");
}

void	chosen_number_actions(t_stacks *stacks, int chose_number)
{
	int		index_a;
	int		index_b;
	int		num_b;
	t_list	*a_stack;

	a_stack = stacks->stack_a;
	while (*(int *)a_stack->content != chose_number)
		a_stack = a_stack->next;
	num_b = chose_number_b(stacks, *(int *)a_stack->content);
	index_a = pos(stacks->stack_a, *(int *)a_stack->content);
	index_b = pos(stacks->stack_b, num_b);
	move_number(stacks, index_a, index_b);
	do_action(stacks);
}
