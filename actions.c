/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:49:09 by musisman          #+#    #+#             */
/*   Updated: 2025/02/17 20:34:29 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void actions(t_stacks *stacks, char *str)
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
