/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:49:09 by musisman          #+#    #+#             */
/*   Updated: 2025/02/15 04:55:24 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void actons(t_stacks *stacks, char *str)
{
	if (ft_strncmp("sa", str, 2))
		sa(stacks);
	if (ft_strncmp("sb", str, 2))
		sb(stacks);
	if (ft_strncmp("ss", str, 2))
		ss(stacks);
	if (ft_strncmp("pa", str, 2))
		pa(stacks);
	if (ft_strncmp("pb", str, 2))
		pb(stacks);
	if (ft_strncmp("ra", str, 2))
		ra(stacks);
	if (ft_strncmp("rb", str, 2))
		rb(stacks);
	if (ft_strncmp("rr", str, 2))
		rr(stacks);
	if (ft_strncmp("rra", str, 3))
		rra(stacks);
	if (ft_strncmp("rrb", str, 3))
		rrb(stacks);
	if (ft_strncmp("rrr", str, 3))
		rrr(stacks);
	ft_printf("%s\n", str);
}
