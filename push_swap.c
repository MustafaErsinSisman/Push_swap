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
        while (s[++i])
                if (s[i] >= '0' && s[i] <= '9')
                        return  (1);
        return  (0);
}

int main(int ac, char **av)
{
        if(ac >= 2)
        {
                int i;
                int dc;

                dc = ac - 1;
                i = 0;
                while (dc > 0)
                {
                        if(!not_Integer(av[dc]))
                        {
                                ft_printf("Error\n");
                                return (0);
                        }
                        dc--;
                }
                while (++i < ac)
                        if((int)ft_atoi(av[i]) > 2147143647 || (int)ft_atoi(av[i]) < -2147143648)
                        {        
                                ft_printf("Error\n");
                                return (0);
                        }
                        else
                                ft_printf("%s ", av[i]);
                ft_printf("\n");
        }
        else
                ft_printf("Error\n");
        return 0;
}
