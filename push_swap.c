/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:36:52 by musisman          #+#    #+#             */
/*   Updated: 2025/01/16 16:36:52 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int not_Integer(char *s)
{
        int i;

        if(!s)
                return (0);
        i  = -1;
        if (s[i + 1] == '-' || s[i + 1] == '+')
                i++;
        while (s[++i])
                if (s[i] < '0' || s[i] > '9')
                        return  (0);
        return  (1);
}

int main(int ac, char **av)
{
        if(ac >= 2)
        {
                int i;
                int dc;
                long value;

                dc = ac - 1;
                while (dc > 0)
                {
                        if(!not_Integer(av[dc]))
                        {
                                ft_printf("Error\n");
                                return (0);
                        }
                        value = 0;
                        i = -1;
                        if (av[dc][i + 1] == '-' || av[dc][i + 1] == '+')
                                i++;
                        while (av[dc][++i])
                                value = (av[dc][i] - '0') + (value * 10);
                        printf("*%lu* ",value);
                        if(value > INT_MAX || value < INT_MIN)
                        {        
                                ft_printf("Error\n");
                                return (0);
                        }
                        dc--;
                }
                i = 0;
                while (++i < ac)
                        ft_printf("%s ", av[i]);
                ft_printf("\n");
        }
        else
                ft_printf("Error\n");
        return 0;
}
