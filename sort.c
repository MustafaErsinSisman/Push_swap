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

#include "push_swap.h"

static void	sort_b(t_stacks *stacks)
{
	int	max_indis;
	int	rev_moves;

	if (is_sort(stacks->stack_b) != 1)
	{
		max_indis = pos(stacks->stack_b, chose_number_b(stacks, INT_MIN));
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

static void	move_b_to_a(t_stacks *stacks)
{
	int	last_a;
	int	first_a;
	int	num_b;

	while (stacks->stack_b)
	{
		num_b = *(int *)stacks->stack_b->content;
		last_a = *(int *)ft_lstlast(stacks->stack_a)->content;
		while ((last_a > num_b))
		{
			actions(stacks, "rra");
			last_a = *(int *)ft_lstlast(stacks->stack_a)->content;
			first_a = *(int *)stacks->stack_a->content;
			if (first_a < last_a)
				break ;
		}
		actions(stacks, "pa");
		if (is_sort(stacks->stack_a) == -1)
			break ;
	}
}

void	so_sort_time(t_stacks *stacks)
{
	int	chose_number;

	actions(stacks, "pb");
	if (stacks->count_a > 4)
		actions(stacks, "pb");
	while (ft_lstsize(stacks->stack_a) > 3)
	{
		chose_number = chosen_number(stacks);
		chosen_number_actions(stacks, chose_number);
		actions(stacks, "pb");
	}
	sort_b(stacks);
	if (is_sort(stacks->stack_a) != -1)
		is_three_node(stacks);
	move_b_to_a(stacks);
	while (stacks->count_b)
		actions(stacks, "pa");
	
	while (is_sort(stacks->stack_a) != -1)
		actions(stacks, "rra");
}
