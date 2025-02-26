/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:39:15 by musisman          #+#    #+#             */
/*   Updated: 2025/02/26 16:40:25 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		count_a;
	int		count_b;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_stacks;

void		error_text(void);
void		error(t_stacks *stacks);
void		free_split(char **s);
void		free_stacks(t_stacks *stacks);
int			check_args(int ac, char **av);
t_list		*stack_a(int ac, char **av);
t_stacks	*fill_stacks(int ac, char **av);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
int			is_sort(t_list *stack);
void		action(t_stacks *stacks, char *str, int *wrong);

#endif