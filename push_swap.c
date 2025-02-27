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
	t_stacks	*stacks;

	if (ac >= 2)
	{
		if (!check_args(ac, av))
			error_text();
		else
		{
			stacks = fill_stacks(ac, av);
			if (!stacks)
			{
				free_stacks(stacks);
				return (0);
			}
			turk_algorithm(stacks);
			free_stacks(stacks);
		}
	}
	return (0);
}
