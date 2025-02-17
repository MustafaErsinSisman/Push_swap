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

t_list	*array(char **av)
{
	char	**s;
	t_list	*a;
	t_list	*node;
	int		i;
	int		*value;

	i = 0;
	node = NULL;
	a = node;
	s = ft_split(av[1], ' ');
	if (!s || !s[0])
		return (free_split(s), NULL);
	while (s[i])
	{
		value = malloc(sizeof(int));
		if (!value)
			return (free(value), free_split(s), ft_lstclear(&a, free), NULL);
		*value = ft_atoi(s[i++]);
		node = ft_lstnew(value);
		if (!node)
			return (free(value), ft_lstclear(&a, free), free_split(s), NULL);
		ft_lstadd_back(&a, node);
	}
	free_split(s);
	return (a);
}

t_list	*not_array(int ac, char **av)
{
	t_list	*a;
	t_list	*node;
	int		i;
	int		*value;

	i = 0;
	node = NULL;
	a = node;
	while (++i < ac)
	{
		value = malloc(sizeof(int));
		if (!value)
			return (free(value), ft_lstclear(&a, free), NULL);
		*value = ft_atoi(av[i]);
		node = ft_lstnew(value);
		if (!node)
			return (free(value), ft_lstclear(&a, free), NULL);
		ft_lstadd_back(&a, node);
	}
	return (a);
}

t_list	*stack_a(int ac, char **av)
{
	t_list	*a;

	if (ac == 2)
		a = array(av);
	else
		a = not_array(ac, av);
	if (!a)
		ft_lstclear(&a, free);
	return (a);
}

t_stacks	*fill_stacks(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (NULL);
	stacks->stack_a = stack_a(ac, av);
	if (!stacks->stack_a)
		return (free(stacks), NULL);
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
