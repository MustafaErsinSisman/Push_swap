/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:24:35 by musisman          #+#    #+#             */
/*   Updated: 2025/02/23 20:24:59 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_in_a(t_list *stack_a)
{
	t_list	*tmp;
	int		min_value;
	int		min_pos;
	int		pos;

	tmp = stack_a;
	min_value = *(int *)stack_a->content;
	min_pos = 0;
	pos = 0;
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
	return (min_pos);
}

void	sort_a(t_stacks *stacks)
{
	int	min_pos;
	int	half;

	min_pos = find_min_in_a(stacks->stack_a);
	half = stacks->count_a / 2;
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

int	find_position_in_a(t_list *stack_a, int nbr)
{
	t_list	*tmp;
	int		pos;
	int		min_pos;
	int		min_nbr;
	int		now_nbr;

	tmp = stack_a;
	pos = 0;
	min_pos = 0;
	min_nbr = *(int *)stack_a->content;
	while (tmp)
	{
		now_nbr = *(int *)tmp->content;
		if (now_nbr > nbr && (min_nbr < nbr || now_nbr < min_nbr))
		{
			min_nbr = now_nbr;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	rotate_a(t_stacks *stacks, int pos)
{
	int	half;

	half = stacks->count_a / 2;
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

void	move_b_to_a(t_stacks *stacks)
{
	int	number;
	int	pos;

	while (stacks->stack_b)
	{
		number = *(int *)stacks->stack_b->content;
		pos = find_position_in_a(stacks->stack_a, number);
		rotate_a(stacks, pos);
		actions(stacks, "pa");
	}
}
