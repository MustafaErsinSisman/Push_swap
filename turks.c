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
    int first = *(int *)(a->content);
    int second = *(int *)(a->next->content);
    int third = *(int *)(a->next->next->content);

    // Sıralama koşulları
    if (first > second && first > third)
        ra(&a);
    if (*(int *)(a->content) > *(int *)(a->next->content))
        sa(&a);  // Swap işlemi

    // Tekrar kontrol ve son adım
    if (*(int *)(a->next->content) > *(int *)(a->next->next->content))
    {
        rra(&a);  // Reverse rotate işlemi
        if (*(int *)(a->content) > *(int *)(a->next->content))
            sa(&a);  // Swap tekrar gerekebilir
    }
}   
        write_stack(a);
        write_stack(b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
        return  (1);
}
