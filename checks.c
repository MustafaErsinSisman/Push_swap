/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:53:10 by musisman          #+#    #+#             */
/*   Updated: 2025/01/29 18:47:14 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int is_array(int ac, char **av)
// {
// 	if (ac == 2)

// 	else
// 	{
// 		int i;
// 		int len;

// 		i = 1;
// 		while (av[++i])
// 		{
// 			len = ft_strlen(ft_split(av[i], 32))
// 			if (len > )
// 		}
		
// 		if (av[2])
// 	}

// 	return (1);
// }

static int	not_integer(char *s)
{	
	int	i;

	if (!s)
		return (0);
	i = -1;
	if (s[i + 1] == '-' || s[i + 1] == '+')
		i++;
	while (s[++i])
		if (s[i] < '0' || s[i] > '9')
			return (0);
	return (1);
}

static int	check_atoi(const char *str, long *result)
{
	size_t	i;
	int		sign;

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

int	same(int ac, char **av)
{
	int	i;
	int	j;
	int	leni;
	int	lenj;

	i = 0;
	while (av[++i])
	{
		j = i;
		leni = ft_strlen(av[i]);
		while (av[++j])
		{
			lenj = ft_strlen(av[j]);
			if (ft_strncmp(av[i], av[j], leni) == 0 && leni == lenj)
				return (1);
		}
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	long	value;
	int		len;

	len = ac;
	while (--ac > 0)
	{
		if (!not_integer(av[ac]))
			return (0);
		if (!check_atoi(av[ac], &value))
			return (0);
	}
	if (same(len, av))
		return (0);
	return (1);
}
