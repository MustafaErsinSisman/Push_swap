/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:39:12 by musisman          #+#    #+#             */
/*   Updated: 2025/03/05 16:30:35 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	fill_strin(t_stacks *stacks)
{
	char	*line;
	int		wrong;

	wrong = 0;
	line = get_next_line(0, wrong);
	while (line)
	{
		actions(stacks, line, &wrong);
		if (wrong == 1)
		{
			get_next_line(1, wrong);
			free_stacks(stacks);
			free(line);
			error_text();
		}
		free(line);
		line = get_next_line(0, wrong);
	}
	free(line);
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
