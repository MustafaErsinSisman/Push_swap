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
int check_atoi(const char *str, long *result)
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
        long value;

        while (--ac > 0)
        {
                if(!not_Integer(av[ac]))
                        return (0);
                if (!check_atoi(av[ac], &value))
                        return (0);
        }
        return (1);
}
int main(int ac, char **av)
{
        if(ac >= 2)
        {
                int fd = open("stderr_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
                if (fd < 0)
                {
                    ft_printf(2, "Error: Could not open file\n");
                    return (1);
                }
                dup2(fd, 2);
                if (!check_args(ac, av))
                {
                        ft_printf(2, "Error\n");
                        close(fd);
                }
                else
                        ft_printf(1, "Correct\n");


                char ss[256];
                int b = read(fd,ss,sizeof(ss) - 1);
                lseek(fd, 0, SEEK_SET);
                if (b > 0)
                {
                    ss[b] = '\0';
                    ft_printf(1, "Captured stderr: %s\n", ss);
                }
                close(fd);
        }
        return (0);
}
