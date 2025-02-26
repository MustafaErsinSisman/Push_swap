/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:39:12 by musisman          #+#    #+#             */
/*   Updated: 2025/02/26 16:41:27 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	fill_strin(t_stacks *stacks)
{
	char	*line;
	int		wrong;

	line = get_next_line(0);
	wrong = 0;
	while (line)
	{
		action(stacks, line, &wrong);
		if (wrong == 1)
			error_text();
		free(line);
		line = get_next_line(0);
	}
}

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
			fill_strin(stacks);
			if (is_sort(stacks->stack_a) == -1 && stacks->count_b == 0)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			free_stacks(stacks);
		}
	}
	return (0);
}
