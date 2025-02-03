/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:53:10 by musisman          #+#    #+#             */
/*   Updated: 2025/02/03 17:56:28 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

static int	check_atoi(const char *str, long *result)
{
	size_t	i;
	int		sign;

	*result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '\0' || (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + (str[i++] - '0');
		if ((*result * sign) > INT_MAX || (*result * sign) < INT_MIN)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	*result *= sign;
	return (1);
}

static int	same(int ac, char **av)
{
	int		i;
	int		j;
	long	num1;
	long	num2;

	i = 0;
	if (ac == 2)
	{
		i--;
	}
	while (av[++i])
	{
		if (!check_atoi(av[i], &num1))
			return (0);
		j = i;
		while (av[++j])
		{
			if (!check_atoi(av[j], &num2))
				return (0);
			if (num1 == num2)
				return (0);
		}
	}
	return (1);
}

static int	is_array(int ac, char **av)
{
	char	**s;
	long	value;
	int		i;

	if (ac == 2)
	{
		s = ft_split(av[1], ' ');
		if (!s || !s[0])
			return (free_split(s), 0);
		i = 0;
		while (s[i])
		{
			if (!check_atoi(s[i], &value))
				return (free_split(s), 0);
			i++;
		}
		if (!same(ac, s) && i > 1)
			return (free_split(s), 0);
		free_split(s);
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	long	value;
	int		len;
	int		i;
	int		check;

	check = 1;
	if (!is_array(ac, av))
		check = 0;
	len = 0;
	while (++len < ac && ac > 2)
	{
		i = 0;
		while (av[len][i])
		{
			if (av[len][i] == ' ')
				check = 0;
			i++;
		}
		if (!check_atoi(av[len], &value))
			check = 0;
	}
	if (!same(ac, av) && ac > 2)
		check = 0;
	if (check == 0)
		write(2, "Error\n", 6);
}
