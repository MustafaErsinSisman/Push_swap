/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:36:55 by musisman          #+#    #+#             */
/*   Updated: 2025/01/16 16:36:55 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
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
int			turk_algorithm(t_stacks *stacks);
t_stacks	*fill_stacks(int ac, char **av);
int			pos(t_list *stack, int number);
int			chose_number_b(t_stacks *stacks, int a_number);
int			chosen_number(t_stacks *stacks);
void		chosen_number_actions(t_stacks *stacks, int chose_number);
int			up_and_up(t_stacks *stacks, int index_a, int index_b);
int			down_to_up(t_stacks *stacks, int index_a, int index_b);
int			up_to_down(t_stacks *stacks, int index_a, int index_b);
int			down_and_down(t_stacks *stacks, int index_a, int index_b);
int			move_number(t_stacks *stacks, int index_a, int index_b);
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
void		is_two_node(t_stacks *stacks);
void		is_three_node(t_stacks *stacks);
void		move_b_to_a(t_stacks *stacks);
void		sort_a(t_stacks *stacks);
void		so_sort_time(t_stacks *stacks);
void		actions(t_stacks *stacks, char *str);

#endif