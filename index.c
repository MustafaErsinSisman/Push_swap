/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:20:10 by musisman          #+#    #+#             */
/*   Updated: 2025/02/19 12:20:10 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos(t_list *stack, int number)
{
	t_list	*temp;
	int		pos;

	pos = 0;
	temp = stack;
	while (temp->next)
	{
		if (*(int *)temp->content == number)
			break ;
		pos++;
		temp = temp->next;
	}
	return (pos);
}

int	move_number(t_stacks *stacks, int index_a, int index_b)
{
	int	move;

	move = 0;
	stacks->ra = 0;
	stacks->rb = 0;
	stacks->rr = 0;
	stacks->rra = 0;
	stacks->rrb = 0;
	stacks->rrr = 0;
	if (stacks->count_a / 2 >= index_a && stacks->count_b / 2 >= index_b)
		move = up_and_up(stacks, index_a, index_b);
	else if (stacks->count_a / 2 < index_a && stacks->count_b / 2 >= index_b)
		move = down_to_up(stacks, index_a, index_b);
	else if (stacks->count_a / 2 >= index_a && stacks->count_b / 2 < index_b)
		move = up_to_down(stacks, index_a, index_b);
	else if (stacks->count_a / 2 < index_a && stacks->count_b / 2 < index_b)
		move = down_and_down(stacks, index_a, index_b);
	return (move);
}
