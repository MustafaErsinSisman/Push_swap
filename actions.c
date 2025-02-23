/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:49:09 by musisman          #+#    #+#             */
/*   Updated: 2025/02/23 20:36:09 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actions(t_stacks *stacks, char *str)
{
	if (!ft_strncmp("sa", str, 2))
		sa(stacks);
	else if (!ft_strncmp("sb", str, 2))
		sb(stacks);
	else if (!ft_strncmp("ss", str, 2))
		ss(stacks);
	else if (!ft_strncmp("pa", str, 2))
		pa(stacks);
	else if (!ft_strncmp("pb", str, 2))
		pb(stacks);
	else if (!ft_strncmp("rra", str, 3))
		rra(stacks);
	else if (!ft_strncmp("rrb", str, 3))
		rrb(stacks);
	else if (!ft_strncmp("rrr", str, 3))
		rrr(stacks);
	else if (!ft_strncmp("ra", str, 2))
		ra(stacks);
	else if (!ft_strncmp("rb", str, 2))
		rb(stacks);
	else if (!ft_strncmp("rr", str, 2))
		rr(stacks);
	ft_printf("%s\n", str);
}

int	up_and_up(t_stacks *stacks, int index_a, int index_b)
{
	int	move;

	if (index_a > index_b)
	{
		stacks->rr = index_b;
		stacks->ra = index_a - index_b;
		move = stacks->rr + stacks->ra;
	}
	else
	{
		stacks->rb = index_b - index_a;
		stacks->rr = index_a;
		move = stacks->rr + stacks->rb;
	}
	return (move);
}

int	down_to_up(t_stacks *stacks, int index_a, int index_b)
{
	int	move;

	stacks->rra = stacks->count_a - index_a;
	stacks->rb = index_b;
	move = stacks->rra + stacks->rb;
	return (move);
}

int	up_to_down(t_stacks *stacks, int index_a, int index_b)
{
	int	move;

	stacks->rrb = stacks->count_b - index_b;
	stacks->ra = index_a;
	move = stacks->rrb + stacks->ra;
	return (move);
}

int	down_and_down(t_stacks *stacks, int index_a, int index_b)
{
	int	move_a;
	int	move_b;
	int	move;

	move_a = stacks->count_a - index_a;
	move_b = stacks->count_b - index_b;
	if (move_a >= move_b)
	{
		stacks->rrr = move_b;
		stacks->rra = move_a - move_b;
		move = stacks->rrr + stacks->rra;
	}
	else
	{
		stacks->rrr = move_a;
		stacks->rrb = move_b - move_a;
		move = stacks->rrr + stacks->rrb;
	}
	return (move);
}
