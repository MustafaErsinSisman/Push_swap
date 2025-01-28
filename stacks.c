/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:49:09 by musisman          #+#    #+#             */
/*   Updated: 2025/01/28 22:01:48 by musisman         ###   ########.fr       */
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
