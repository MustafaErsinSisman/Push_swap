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
			error_text();
        	else
        	{
			t_stacks	*stacks;

			stacks = fill_stacks(ac, av);
            		turk_algorithm(stacks);
			// write_stack(stacks);
			// if (is_sort(stacks->stack_a) == 1)
			// 	printf("büyükten küçüğe sıralı \n");
			// else if (is_sort(stacks->stack_a) == -1)
			// 	printf("küçükten büyüğe sıralı \n");
			// else
			// 	printf("sıralı değil \n");
			free_stacks(stacks);
        	}
	}
	return (0);
}
