/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:20:10 by musisman          #+#    #+#             */
/*   Updated: 2025/02/19 12:20:10 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pos(t_list *stack, int number)
{
        t_list *temp;
        int pos;

        pos = 0;
        temp = stack;
        while (temp->next)
        {
                if (*(int *)temp->content == number)
                        break ;
                pos++;
                temp = temp->next;
        }
        return (pos);
}