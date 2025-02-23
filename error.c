/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 05:33:45 by musisman          #+#    #+#             */
/*   Updated: 2025/02/12 05:33:45 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_text(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	ft_lstclear(&stacks->stack_a, free);
	ft_lstclear(&stacks->stack_b, free);
	free(stacks);
}

void	error(t_stacks *stacks)
{
	free_stacks(stacks);
	error_text();
}
