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

int	is_sort(t_list *stack)
{
	t_list	*tmp;
	int		min_to_max;
	int		max_to_min;

	min_to_max = 1;
	max_to_min = 1;
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

static void	is_two_node(t_stacks *stacks)
{
	if (stacks->count_a == 2)
	{
		actions(stacks, "sa");
		free_stacks(stacks);
		exit(0);
	}
}

void	is_three_node(t_stacks *stacks)
{
	t_list	*tmp;

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

int	turk_algorithm(t_stacks *stacks)
{
	if (is_sort(stacks->stack_a) == -1)
	{
		free_stacks(stacks);
		exit(0);
	}
	is_two_node(stacks);
	is_three_node(stacks);
	so_sort_time(stacks);
	return (1);
}
