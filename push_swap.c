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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int check_args(int ac, char **av);  // check_args fonksiyonu
extern void free_split(char **s);          // free_split fonksiyonu

// Dosyaya çıktıyı yazan fonksiyon
void append_to_file(const char *text)
{
    FILE *file = fopen("output.txt", "a");
    if (!file)
    {
        perror("Dosya açılamadı");
        return;
    }
    fputs(text, file);
    fclose(file);
}

// Dosyanın içeriğini temizleyen fonksiyon
void clean_file()
{
    FILE *file = fopen("output.txt", "w");  // "w" moduyla dosyayı açıyoruz, bu dosyayı sıfırlar
    if (!file)
    {
        perror("Dosya açılamadı");
        return;
    }
    fclose(file);  // Dosyayı kapatıp, içeriğini sıfırlamış olduk
}

int main(int argc, char **argv)
{
    // Eğer komut "clean" ise dosyayı temizleyelim
    if (argc == 2 && strcmp(argv[1], "clean") == 0)
    {
        clean_file();
        printf("output.txt dosyasının içeriği temizlendi.\n");
        return 0;
    }

    // Terminal çıktısını dosyaya eklemek için freopen kullanıyoruz
    FILE *orig_stdout = stdout;  // Geçici olarak terminale yazan çıktıyı kaydediyoruz
    FILE *file = fopen("output.txt", "a");  // Dosyayı append mode (ekleme) ile açıyoruz
    if (!file)
    {
        perror("Dosya açılamadı");
        return 1;
    }

    // Standart çıktıyı (stdout) dosyaya yönlendiriyoruz
    stdout = file;

    // Test edilen argümanları dosyaya yazıyoruz
    append_to_file("\n\nTest Başlatıldı: ");
    for (int i = 1; i < argc; i++)
    {
        append_to_file(argv[i]);
        if (i < argc - 1)
            append_to_file(" ");
    }
    append_to_file("\n");

    // Burada check_args fonksiyonunu çağırmak için bir test girişi yapıyoruz
    int result = check_args(argc, argv); // check_args fonksiyonunu çağırıyoruz

    if (result)
        printf("Geçerli input\n");
    else
        printf("Hata\n");

    // Terminal çıktısını tekrar eski haline getiriyoruz
    stdout = orig_stdout;

    // Aynı zamanda terminalde de çıktı görmek istiyorsan
    printf("Test tamamlandı. Sonuçlar output.txt dosyasına eklendi.\n");

    // Program sonucu dosyaya eklenmiş olacak
    append_to_file("\nTest bitti.\n");

    return 0;
}




// int	main(int ac, char **av)
// {
// 	if (ac >= 2)
// 	{
// 		if (!check_args(ac, av))
// 			write(2, "Error\n", 6);
// 		else
//                         ft_printf("Correct\n");
	
// 	}
// 	return (0);
// }

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