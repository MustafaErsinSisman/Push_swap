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
			write(2, "Error\n", 6);
		else
		{}
	
	}
	return (0);
}

// tüm methodları deneyen bir script

// if (ac >= 2)
// 	{
// 		if (!check_args(ac, av))
// 			write(2, "Error\n", 6);
// 		else
// 		{
// 			t_list *a;
// 			t_list *b;

// 			a = stack_a(ac, av);
// 			b = NULL;
// 			t_list *tmp = a;
// 			printf("Başlangıç durumu:\n");
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("-----------------\n");
// 			pb(&a,&b);
// 			printf("\n1. pb sonrası:\n\nA stack:\n");
// 			tmp = a;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("\nB stack:\n");
// 			tmp = b;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("-----------------\n");
// 			pb(&a,&b);
// 			printf("\n2. pb sonrası:\n\nA stack:\n");
// 			tmp = a;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("\nB stack:\n");
// 			tmp = b;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("-----------------\n");
// 			pb(&a,&b);
// 			printf("\n3. pb sonrası:\n\nA stack:\n");
// 			tmp = a;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("\nB stack:\n");
// 			tmp = b;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
			
// 			printf("-----------------\n");
// 			ss(&a,&b);
// 			printf("\nss sonrası:\n\nA stack:\n");
// 			tmp = a;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("\nss sonrası:\n\nB stack:\n");
// 			tmp = b;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("-----------------\n");
// 			rr(&a,&b);
// 			printf("\nrr sonrası:\n\nA stack:\n");
// 			tmp = a;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("\nrr sonrası:\n\nB stack:\n");
// 			tmp = b;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("-----------------\n");
// 			rrr(&a,&b);
// 			printf("\nrrr sonrası:\n\nA stack:\n");
// 			tmp = a;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			printf("\nrrr sonrası:\n\nB stack:\n");
// 			tmp = b;
// 			while(tmp)
// 			{
// 				printf("%d\n",*(int *)(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			ft_lstclear(&a, free);
// 			ft_lstclear(&b, free);
// 		}
// 	}
// 	return (0);