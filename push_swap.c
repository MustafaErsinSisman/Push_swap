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
int safe_atoi(const char *str, long *result)
{
    size_t i;
    int sign;

    i = 0;
    sign = 1;
    *result = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        *result = *result * 10 + (str[i] - '0');
        if ((*result * sign) > INT_MAX || (*result * sign) < INT_MIN)
            return (0);
        i++;
    }
    if (str[i] != '\0')
        return (0);
    *result *= sign;
    return (1);
}
int check_args(int ac, char **av)
{
        int dc;
        long value;

        dc = ac -1;
         while (dc > 0)
                {
                        if(!not_Integer(av[dc]))
                        {
                                ft_printf("Error\n");
                                return (0);
                        }
                        if (!safe_atoi(av[dc], &value))
                        {
                                ft_printf("Error\n");
                                return (0);
                        }
                        dc--;
                }
        return (1);
}
int main(int ac, char **av)
{
        if(ac >= 2)
        {
                int i;
                
                if (!check_args(ac, av))
                        return (0);
                i = 0;
                while (++i < ac)
                        ft_printf("%s ", av[i]);
                ft_printf("\n");
        }
        else
                ft_printf("Error\n");
        return 0;
}
