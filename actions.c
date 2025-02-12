/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:49:09 by musisman          #+#    #+#             */
/*   Updated: 2025/02/12 18:22:27 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void actons(t_list *a, t_list *b, char *str)
{
	if (ft_strncmp("sa", str, 2))
		sa(&a);
	if (ft_strncmp("sb", str, 2))
		sb(&b);
	if (ft_strncmp("ss", str, 2))
		ss(&a, &b);
	if (ft_strncmp("pa", str, 2))
		pa(&a, &b);
	if (ft_strncmp("pb", str, 2))
		pb(&a, &b);
	if (ft_strncmp("ra", str, 2))
		ra(&a);
	if (ft_strncmp("rb", str, 2))
		rb(&b);
	if (ft_strncmp("rr", str, 2))
		rr(&a, &b);
	if (ft_strncmp("rra", str, 3))
		rra(&a);
	if (ft_strncmp("rrb", str, 3))
		rrb(&b);
	if (ft_strncmp("rrr", str, 3))
		rrr(&a, &b);
	ft_printf("%s\n", str);
}
