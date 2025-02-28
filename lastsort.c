/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:24:35 by musisman          #+#    #+#             */
/*   Updated: 2025/02/28 22:32:33 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_in_a(t_list *stack_a)
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

static void	last_sort(int first_a, int last_a, int num_b, t_stacks *stacks)
{
	while (stacks->stack_b)
	{
		num_b = *(int *)stacks->stack_b->content;
		if (first_a > num_b && last_a < num_b)
			actions(stacks, "pa");
		else if (last_a > num_b)
		{
			while (((first_a < num_b && last_a > num_b) || last_a > num_b))
			{
				actions(stacks, "rra");
				last_a = *(int *)ft_lstlast(stacks->stack_a)->content;
				first_a = *(int *)(stacks->stack_a)->content;
				if (first_a < last_a)
					break ;
			}
			actions(stacks, "pa");
		}
		else
			actions(stacks, "pa");
		first_a = *(int *)(stacks->stack_a)->content;
		last_a = *(int *)ft_lstlast(stacks->stack_a)->content;
		if (is_sort(stacks->stack_a) == -1)
			break ;
	}
}

void	move_b_to_a(t_stacks *stacks)
{
	int	first_a;
	int	last_a;
	int	num_b;

	first_a = *(int *)stacks->stack_a->content;
	last_a = *(int *)ft_lstlast(stacks->stack_a)->content;
	num_b = *(int *)stacks->stack_b->content;
	last_sort(first_a, last_a, num_b, stacks);
}
