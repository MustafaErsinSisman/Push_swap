/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:49:19 by musisman          #+#    #+#             */
/*   Updated: 2025/02/26 16:40:48 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	action(t_stacks *stacks, char *str, int *wrong)
{
	if (!ft_strcmp("sa\n", str))
		sa(stacks);
	else if (!ft_strcmp("sb\n", str))
		sb(stacks);
	else if (!ft_strcmp("ss\n", str))
		ss(stacks);
	else if (!ft_strcmp("pa\n", str))
		pa(stacks);
	else if (!ft_strcmp("pb\n", str))
		pb(stacks);
	else if (!ft_strcmp("rra\n", str))
		rra(stacks);
	else if (!ft_strcmp("rrb\n", str))
		rrb(stacks);
	else if (!ft_strcmp("rrr\n", str))
		rrr(stacks);
	else if (!ft_strcmp("ra\n", str))
		ra(stacks);
	else if (!ft_strcmp("rb\n", str))
		rb(stacks);
	else if (!ft_strcmp("rr\n", str))
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
