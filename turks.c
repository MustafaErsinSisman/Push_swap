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

void write_stack(t_list *a, t_list *b)
{
    t_list *tmp_a = a;
    t_list *tmp_b = b;

    ft_printf("\n ---------     ---------\n| StackA: |   | StackB: |\n");
    ft_printf(" ---------     ---------\n");
    while (tmp_a || tmp_b)
    {
        if (tmp_a)
        {
            ft_printf("|    %d    |", *(int *)(tmp_a->content));
            tmp_a = tmp_a->next;
        }
        else
            ft_printf("|         |");
        ft_printf("   ");
        if (tmp_b)
        {
            ft_printf("|    %d    |", *(int *)(tmp_b->content));
            tmp_b = tmp_b->next;
        }
        else
            ft_printf("|         |");
        ft_printf("\n");
    }
    ft_printf(" ---------     ---------\n");
}
#include <math.h>

int get_position_in_a(t_list *a, int value)
{
    int pos = 0;
    while (a)
    {
        if (*(int *)(a->content) == value)
            return pos;
        a = a->next;
        pos++;
    }
    return -1;
}

int get_position_in_b(t_list *b, int value)
{
    int pos = 0;
    int best_match = -1;
    int best_match_pos = 0;
    t_list *tmp = b;

    while (tmp)
    {
        int b_value = *(int *)(tmp->content);
        if (b_value > value)
        {
            if (best_match == -1 || b_value < best_match)
            {
                best_match = b_value;
                best_match_pos = pos;
            }
        }
        tmp = tmp->next;
        pos++;
    }

    if (best_match == -1)
    {
        int max_pos = 0;
        int max_value = INT_MIN;
        pos = 0;
        tmp = b;
        while (tmp)
        {
            if (*(int *)(tmp->content) > max_value)
            {
                max_value = *(int *)(tmp->content);
                max_pos = pos;
            }
            tmp = tmp->next;
            pos++;
        }
        return max_pos + 1;
    }
    return best_match_pos;
}

int action_number(t_list *a, t_list *b)
{
    t_stacks actions;
    t_list *tmp = a;
    int min_moves = INT_MAX;
    int best_value = 0;

    actions.stack_a = a;
    actions.stack_b = b;
    actions.count_a = ft_lstsize(a);
    actions.count_b = ft_lstsize(b);

    while (tmp)
    {
        int value = *(int *)(tmp->content);
        int index_a = get_position_in_a(a, value);
        int index_b = get_position_in_b(b, value);

        actions.ra = index_a;
        actions.rra = actions.count_a - index_a;
        actions.rb = index_b;
        actions.rrb = actions.count_b - index_b;

        actions.rr = fmin(actions.ra, actions.rb);
        actions.ra -= actions.rr;
        actions.rb -= actions.rr;

        actions.rrr = fmin(actions.rra, actions.rrb);
        actions.rra -= actions.rrr;
        actions.rrb -= actions.rrr;

        int total_moves = actions.ra + actions.rb + actions.rr + actions.rra + actions.rrb + actions.rrr;

        if (total_moves < min_moves)
        {
            min_moves = total_moves;
            best_value = value;
        }
        tmp = tmp->next;
    }

    ft_printf("En az hamlede taşınacak eleman: %d\n", best_value);
    ft_printf("Hamleler: RA: %d, RB: %d, RR: %d, RRA: %d, RRB: %d, RRR: %d\n", 
            actions.ra, actions.rb, actions.rr, actions.rra, actions.rrb, actions.rrr);
    
    return min_moves;
}


int turk_algorithm(t_stacks *stacks)
{
        // sıralımı bak
            // sıralıysa exit
        // değilse 2 argüman mı
            // evetse sa
        // değilse 3 argüman mı bak
            // evetse ona göre sırala
        // değilse ona göre sırala
        


	    
        return  (1);
}
//doğru sıralama
        // ft_printf("ilk durum\n");
        // write_stack(a, b);
        // pb(&a,&b);
        // pb(&a,&b);
        // ft_printf("ilk 2 pb yapıldı");
        // write_stack(a, b);
        // pb(&a, &b);
        // ft_printf("1 için hamle sayısı 1 pb yapıldı");
        // write_stack(a, b);
        // rrb(&b);
        // pb(&a, &b);
        // ft_printf("4 için hamle sayısı 2 rrb ve pb yapıldı");
        // write_stack(a, b);
        // rra(&a);
        // pb(&a, &b);
        // ft_printf("5 için hamle sayısı 2 rra ve pb yapıldı");
        // write_stack(a, b);
        // rrr(&a, &b);
        // pb(&a, &b);
        // ft_printf("0 için hamle sayısı 2 rrr ve pb yapıldı");
        // write_stack(a, b);
        // rrb(&b);
        // pb(&a, &b);
        // ft_printf("2 için hamle sayısı 2 rrb ve pb yapıldı");
        // write_stack(a, b);
        // ft_printf("a'da 3 eleman kaldı artık işlemler değişti bu 3 eleman küçükten büyüğe sıralanmalı bu koşulda ra yetiyor");
        // ra(&a);
        // write_stack(a, b);
        // ft_printf("artık iki stack de sıralandı şimdi uygun yerlere b'den a'ya atılacak sayılar\n");
        // ft_printf("bu koşulda 8 üstüne 7 gelecek o yüzden rb rb rb ra pa yapıyoruz");
        // rb(&b);
        // rb(&b);
        // rb(&b);
        // ra(&a);
        // pa(&a, &b);
        // write_stack(a, b);
        // ft_printf("şimdi de 6 üstüne 5 gelecek rra ve pa yapıyoruz");
        // rra(&a);
        // pa(&a, &b);
        // write_stack(a, b);
        // ft_printf("artık b'dekiler sıralı olduğu için hepsini atabiliriz 5 tane pa yapıyoruz ve sıralanıyor");
        // pa(&a, &b);
        // pa(&a, &b);
        // pa(&a, &b);
        // pa(&a, &b);
        // pa(&a, &b);
        // write_stack(a, b);

        //5 1 7 2 4 3 9 0 6 8
        // write_stack(a, b);
        // pb(&a, &b);
        // pb(&a, &b);
        // write_stack(a, b);
        // rb(&b);// 7
        // pb(&a, &b);
        // write_stack(a, b);
        // rrb(&b);// 2
        // pb(&a, &b);
        // write_stack(a, b);
        // pb(&a, &b); // 4
        // write_stack(a, b);
        // rb(&b);// 3
        // pb(&a, &b);
        // write_stack(a, b);
        // rrr(&a, &b); // 6
        // rrb(&b);
        // pb(&a, &b);
        // write_stack(a, b);
        // ra(&a);// a sırala 3 tane kaldığı için
        // rrb(&b);// b sıralanamalı son hali büyükten küçüğe olmalı
        // ra(&a);// b atmak için 0 aşağı aldık
        // pa(&a, &b);// b atmaya başlandı
        // write_stack(a, b);
        // pa(&a, &b);
        // write_stack(a, b);
        // pa(&a, &b);
        // write_stack(a, b);
        // pa(&a, &b);
        // write_stack(a, b);
        // pa(&a, &b);
        // write_stack(a, b);
        // pa(&a, &b);
        // write_stack(a, b);
        // pa(&a, &b);
        // write_stack(a, b);
        // rra(&a);// 0 aşağıda kaldı yukarı aldık
        // write_stack(a, b);