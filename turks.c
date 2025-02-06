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

// void write_stack(t_list *a, t_list *b)
// {
//     t_list *tmp_a = a;
//     t_list *tmp_b = b;

//     ft_printf("\n --------------       --------------\n|   Stack A:   |     |   Stack B:   |\n");
//     ft_printf(" --------------       --------------\n");
//     while (tmp_a || tmp_b)
//     {
//         if (tmp_a)
//         {
//             printf("|      %d       |", *(int *)(tmp_a->content));
//             tmp_a = tmp_a->next;
//         }
//         else
//             printf("|              |");
//         printf("     ");
//         if (tmp_b)
//         {
//             printf("|      %d       |", *(int *)(tmp_b->content));
//             tmp_b = tmp_b->next;
//         }
//         else
//             printf("|              |");
//         printf("\n");
//     }
//     ft_printf(" --------------       --------------\n\n");
// }

void write_stack(t_list *a, t_list *b)
{
    int len_a = ft_lstsize(a);
    int len_b = ft_lstsize(b);
    int max_height = (len_a > len_b) ? len_a : len_b;

    printf("\n ---------      --------------\n");
    printf("| StackA: |      |  Stack B:   |\n");
    printf(" ---------      --------------\n");

    for (int i = 0; i < max_height; i++)
    {
        // Stack A'nın elemanlarını yukarıdan aşağı yazdır
        printf("|");
        if (i < len_a)
        {
            printf("    %d    |", *(int *)(a->content));
            a = a->next;
        }
        else
            printf("             |");

        printf("     |");

        // Stack B'nin elemanlarını alttan yukarıya yazdır
        if (i >= max_height - len_b)
        {
            t_list *tmp = b;
            for (int j = 0; j < (max_height - i - 1); j++)
                tmp = tmp->next;
            printf("    %d    |\n", *(int *)(tmp->content));
        }
        else
            printf("            |\n");
    }

    printf(" ---------     --------------\n");
}



// int action_number(t_list  *a, t_list *b)
// {
//         t_stacks actions;

//         actions.stack_a = a;
//         actions.stack_b = b;

// }

int turk_algorithm(t_list *a, t_list *b)
{
        // int len;

        // len = ft_lstsize(a);

        printf("ilk durum\n");
        write_stack(a, b);
        pb(&a, &b);
        printf("pb yapıldı\n");
        write_stack(a, b);
        pb(&a, &b);
        printf("pb yapıldı\n");
        write_stack(a, b);

	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
        return  (1);
}
