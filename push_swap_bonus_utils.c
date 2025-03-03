/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:49:19 by musisman          #+#    #+#             */
/*   Updated: 2025/03/03 11:10:46 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	actions(t_stacks *stacks, char *str, int *wrong)
{
	if (!ft_strncmp("sa\n", str, 3))
		sa(stacks);
	else if (!ft_strncmp("sb\n", str, 3))
		sb(stacks);
	else if (!ft_strncmp("ss\n", str, 3))
		ss(stacks);
	else if (!ft_strncmp("pa\n", str, 3))
		pa(stacks);
	else if (!ft_strncmp("pb\n", str, 3))
		pb(stacks);
	else if (!ft_strncmp("rra\n", str, 4))
		rra(stacks);
	else if (!ft_strncmp("rrb\n", str, 4))
		rrb(stacks);
	else if (!ft_strncmp("rrr\n", str, 4))
		rrr(stacks);
	else if (!ft_strncmp("ra\n", str, 3))
		ra(stacks);
	else if (!ft_strncmp("rb\n", str, 3))
		rb(stacks);
	else if (!ft_strncmp("rr\n", str, 3))
		rr(stacks);
	else
		*wrong = 1;
}

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
