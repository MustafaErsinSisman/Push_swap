/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:03:49 by musisman          #+#    #+#             */
/*   Updated: 2025/02/03 19:03:49 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void write_stack(t_list *a)
{
        t_list *tmp;
        
        tmp = a;
	printf("-----------------\n");
	while(tmp)
	{
		printf("%d\n",*(int *)(tmp->content));
		tmp = tmp->next;
	}
	printf("-----------------\n");
}

int turk_algorithm(t_list *a, t_list *b)
{
        int len;

        len = ft_lstsize(a);
       if (len == 1)
        return (1);
        else if (len == 2)
        {
            if (*(int *)(a->content) > *(int *)(a->next->content))
                ra(&a);
        }
        else if (len == 3)
        {
            int i = 0;
            int max;
            t_list *tmp = a;

            while (tmp->next)
            {
                i = 0;
                while (i< len)
                {
                        if (*(int *)(tmp->content) > *(int *)(a->next->content))
                                
                        i++;  
                }
                len--;
                tmp = tmp->next;
            }
            
        }     
        write_stack(a);
        write_stack(b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
        return  (1);
}
