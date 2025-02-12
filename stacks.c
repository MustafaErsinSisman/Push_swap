/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 05:26:04 by musisman          #+#    #+#             */
/*   Updated: 2025/02/12 05:26:04 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_a(int ac, char **av)
{
	t_list	*a;
	t_list	*node;
	int		i;
	int		*value;

	i = 1;
	node = NULL;
	a = node;
	while (i < ac)
	{
		value = malloc(sizeof(int));
		if (!value)
			return (NULL);
		*value = ft_atoi(av[i]);
		node = ft_lstnew(value);
		ft_lstadd_back(&a, node);
		i++;
	}
	return (a);
}

t_stacks *fill_stacks(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		error_text();
        stacks->stack_a =stack_a(ac, av);
	stacks->stack_b = NULL;
	stacks->count_a = ft_lstsize(stacks->stack_a);
	stacks->count_b = ft_lstsize(stacks->stack_b);
	stacks->ra = 0;
	stacks->rb = 0;
	stacks->rr = 0;
	stacks->rra = 0;
	stacks->rrb = 0;
	stacks->rrr = 0;
	return (stacks);
}