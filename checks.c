/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:53:10 by musisman          #+#    #+#             */
/*   Updated: 2025/01/31 21:57:23 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void free_split(char **s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 		free(s[i++]);
// 	free(s);	
// }

// static int	check_atoi(const char *str, long *result)
// {
// 	size_t	i;
// 	int		sign;

// 	i = 0;
// 	sign = 1;
// 	*result = 0;
// 	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		*result = *result * 10 + (str[i] - '0');
// 		if ((*result * sign) > INT_MAX || (*result * sign) < INT_MIN)
// 			return (0);
// 		i++;
// 	}
// 	if (str[i] != '\0')
// 		return (0);
// 	*result *= sign;
// 	return (1);
// }

// int	same(char **av)
// {
// 	int	i;
// 	int	j;
// 	int	leni;
// 	int	lenj;

// 	i = 0;
// 	while (av[++i])
// 	{
// 		j = i;
// 		leni = ft_strlen(av[i]);
// 		while (av[++j])
// 		{
// 			lenj = ft_strlen(av[j]);
// 			if (ft_strncmp(av[i], av[j], leni) == 0 && leni == lenj)
// 				return (1);
// 		}
// 	}
// 	return (0);
// }

// static int is_array(int ac, char **av)
// {
//     char **s;
//     long value;
//     int i;

//     if (ac == 2)
//     {
//         s = ft_split(av[1], ' ');
//         if (!s || !s[0])
//         {
//             free_split(s);
//             return (0);
//         }
//         i = 0;
//         while (s[i])
//         {
//             if (!check_atoi(s[i], &value))
//             {
//                 free_split(s);
//                 return (0);
//             }
//             i++;
//         }
//         if (same(s))
//         {
//             free_split(s);
//             return (0);
//         }
//         free_split(s);
//     }
//     return (1);
// }

// int	check_args(int ac, char **av)
// {
// 	long	value;
// 	int		len;

// 	len = 1;
// 	if (!is_array(ac, av))
// 		return (0);
// 	while (len < ac)
// 		if (!check_atoi(av[len++], &value))
// 			return (0);
// 	if (same(av))
// 		return (0);
// 	return (1);
// }


static void free_split(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);	
}

// static int	check_atoi(const char *str, long *result)
// {
// 	size_t	i;
// 	int		sign;

// 	i = 0;
// 	sign = 1;
// 	*result = 0;
// 	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		*result = *result * 10 + (str[i] - '0');
// 		if ((*result * sign) > INT_MAX || (*result * sign) < INT_MIN)
// 			return (0);
// 		i++;
// 	}
// 	if (str[i] != '\0')
// 		return (0);
// 	*result *= sign;
// 	return (1);
// }

static int check_atoi(const char *str, long *result)
{
	size_t i = 0;
	int sign = 1;

	*result = 0;

	// Başındaki boşlukları atla
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;

	// İşaret kontrolü
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '\0' || (str[i + 1] < '0' || str[i + 1] > '9')) // Sonrasında sayı var mı kontrol et
			return (0);
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// Sayıyı çevir
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + (str[i] - '0');
		if ((*result * sign) > INT_MAX || (*result * sign) < INT_MIN)
			return (0);
		i++;
	}

	// Eğer hala karakter varsa hata ver
	if (str[i] != '\0')
		return (0);

	*result *= sign;
	return (1);
}


// int	same(char **av)
// {
// 	int	i;
// 	int	j;
// 	int	leni;
// 	int	lenj;

// 	i = 0;
// 	while (av[++i])
// 	{
// 		j = i;
// 		leni = ft_strlen(av[i]);
// 		while (av[++j])
// 		{
// 			lenj = ft_strlen(av[j]);
// 			if (ft_strncmp(av[i], av[j], leni) == 0 && leni == lenj)
// 				return (1);
// 		}
// 	}
// 	return (0);
// }

int same(char **av)
{
	int i, j;
	long num1, num2;

	i = 0;
	while (av[++i])
	{
		if (!check_atoi(av[i], &num1)) // Sayıyı long olarak al
			return (0);
		j = i;
		while (av[++j])
		{
			if (!check_atoi(av[j], &num2)) // Diğer sayıyı da long olarak al
				return (0);
			if (num1 == num2) // Sayılar aynı mı kontrol et
				return (1);
		}
	}
	return (0);
}


static int is_array(int ac, char **av)
{
    char **s;
    long value;
    int i;

    if (ac == 2)
    {
        printf("is_array: Argüman string olarak alındı:*%s*\n", av[1]);
        s = ft_split(av[1], ' ');
        if (!s || !s[0])
        {
            printf("is_array: Split işlemi başarısız!\n");
            free_split(s);
            return (0);
        }
        i = 0;
        while (s[i])
        {
            printf("is_array: Kontrol ediliyor -> *%s*\n", s[i]);
            if (!check_atoi(s[i], &value))
            {
                printf("is_array: check_atoi başarısız!*%s*\n", s[i]);
                free_split(s);
                return (0);
            }
            i++;
        }
        if (same(s) && i > 1)
        {
            printf("is_array: Aynı sayı bulundu, hata!\n");
            free_split(s);
            return (0);
        }
        printf("is_array: Geçerli input!\n");
        free_split(s);
    }
    return (1);
}


int check_args(int ac, char **av)
{
    long value;
    int len;
    int i;

    printf("check_args: Başlatıldı\n");
    
    if (!is_array(ac, av))
    {
        printf("check_args: is_array başarısız!\n");
        return (0);
    }

    len = 0;
    while (++len < ac && ac > 2)
    {
        printf("check_args: check_atoi kontrol ediliyor -> *%s*\n", av[len]);

        i = 0;
        while (av[len][i])
        {
            if (av[len][i] == ' ')
            {
                printf("check_args: Argüman içinde boşluk bulundu -> *%s*\n", av[len]);
                return (0);
            }
            i++;
        }

        if (!check_atoi(av[len], &value))
        {
            printf("check_args: check_atoi başarısız!\n");
            return (0);
        }
    }

    if (same(av) && ac > 2 && !is_array(ac, av))
    {
        printf("check_args: Aynı sayı bulundu!\n");
        return (0);
    }

    printf("check_args: Tüm kontroller geçti!\n");
    return (1);
}

