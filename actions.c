/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:49:09 by musisman          #+#    #+#             */
/*   Updated: 2025/02/12 05:30:45 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void actons(t_list *a, t_list *b, char *str)
{
	if (str == "sa")
		sa(&a);
	if (str == "sb")
		sb(&b);
	if (str == "ss")
		ss(&a, &b);
	if (str == "pa")
		pa(&a, &b);
	if (str == "pb")
		pb(&a, &b);
	if (str == "ra")
		ra(&a);
	if (str == "rb")
		rb(&b);
	if (str == "rr")
		rr(&a, &b);
	if (str == "rra")
		rra(&a);
	if (str == "rrb")
		rrb(&b);
	if (str == "rrr")
		rrr(&a, &b);
	ft_printf("%s\n", str);
}
