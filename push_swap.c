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
		{
			t_list *a;
			t_list *b;

			a = stack_a(ac, av);
			b = NULL;
			t_list *tmp = a;
			printf("Başlangıç durumu:\n");
			while(tmp)
			{
				printf("%d\n",*(int *)(tmp->content));
				tmp = tmp->next;
			}
			pb(&a,&b);
			printf("\nİlk pb sonrası:\n\nA stack:\n");
			tmp = a;
			while(tmp)
			{
				printf("%d\n",*(int *)(tmp->content));
				tmp = tmp->next;
			}
			printf("\nB stack:\n");
			tmp = b;
			while(tmp)
			{
				printf("%d\n",*(int *)(tmp->content));
				tmp = tmp->next;
			}
			pb(&a,&b);
			printf("\nİkinci pb sonrası:\n\nA stack:\n");
			tmp = a;
			while(tmp)
			{
				printf("%d\n",*(int *)(tmp->content));
				tmp = tmp->next;
			}
			printf("\nB stack:\n");
			tmp = b;
			while(tmp)
			{
				printf("%d\n",*(int *)(tmp->content));
				tmp = tmp->next;
			}
			ft_lstclear(&a, free);
			ft_lstclear(&b, free);
		}
	}
	return (0);
}

// burada basit kontrol var
	// ac 2'den büyükse check args ile kontrol et
	// check args not integer ile bütün argümanların integer olup 
	// olmadığına bakıyor
	// check atoi de integer sınırlarında olup olmadığına bakıyor
	// kontrollerden geçerse return 1 geçemez ise 0

	// if (ac >= 2)
	// {
	// 	if (!check_args(ac, av))
	// 		write(2, "Error\n", 6);
	// 	else
	// 		ft_printf("Correct\n");
	// }


	// basit bir liste ekleme ve yazdırma
	// t_list *lst;
	// t_list *node1;
	// t_list *node2;
	// t_list *node3;

	// int a = 1;
	// int b = 2;
	// int c = 3;

	// node1 = ft_lstnew(&a);
	// node2 = ft_lstnew(&b);
	// node3 = ft_lstnew(&c);
	
	// lst = node1;
	// ft_lstadd_back(&lst,node2);
	// ft_lstadd_back(&lst,node3);;

	// int i = 1;
	// t_list *tmp = lst;
	// while(tmp)
	// {
	// 	printf("node%d : %d\n",i++,*(int *)(tmp->content));
	// 	tmp = tmp->next;
	// }