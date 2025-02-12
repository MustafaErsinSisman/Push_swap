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

void error_text(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	error(t_stacks *stacks)
{
        //t_stacks içindeargs olursa

	// int	i;

	// i = 0;
	// while (stacks->args[i])
	// 	free(stacks->args[i++]);
	//free(stacks->args);
	ft_lstclear(&stacks->stack_a, free);
	ft_lstclear(&stacks->stack_b, free);
	free(stacks);
	error_text();
}