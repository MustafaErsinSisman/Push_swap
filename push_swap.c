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

        i  = 0;
        while (s[i])
                if (s[i] >=  '0' && s[i] <= '9')
                        return  (1);
        return  (0);
}

int main(int ac, char **av)
{
        if(ac >= 2)
        {
                int i;
                int j;
                int dc;

                dc = ft_strlen(av);
                i = 0;
                j = 0;
                while (dc > 0)
                {
                        if(!not_Integer(av[dc]))
                        {
                                ft_printf("Error\n");
                                break;
                        }
                        while (++i < ac)
                                ft_printf("%s ", &av[i][0]);
                        dc--;
                }
                
                ft_printf("\n");
        }
        else
                ft_printf("Error\n");
        return 0;
}
