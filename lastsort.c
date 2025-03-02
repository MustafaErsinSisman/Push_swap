/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:24:35 by musisman          #+#    #+#             */
/*   Updated: 2025/03/02 03:31:29 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
