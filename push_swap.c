/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:36:52 by musisman          #+#    #+#             */
/*   Updated: 2025/01/26 20:34:20 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (!check_args(ac, av))
            			ft_putstr_fd("Error\n", 2);
        	else
        	{
			t_stacks *stacks;
			
			fill_stacks(stacks);
            		turk_algorithm(stacks);
        	}
	}
	return (0);
}
