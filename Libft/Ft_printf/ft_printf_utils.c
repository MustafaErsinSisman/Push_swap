/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:19:14 by musisman          #+#    #+#             */
/*   Updated: 2024/11/14 18:47:00 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
		ft_putchar(s[i++], fd);
	return (i);
}

int	ft_putnbr_base(long nbr, char *base, int fd)
{
	int	i;
	int	base_len;

	i = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		ft_putchar('-', fd);
		nbr *= -1;
		i++;
	}
	if (nbr >= base_len)
		i += ft_putnbr_base((nbr / base_len), base, fd);
	i += ft_putchar(base[nbr % base_len], fd);
	return (i);
}

static int	ft_ptrnbr_base(unsigned long nbr, char *base, int fd)
{
	size_t	i;
	size_t	base_len;

	i = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		i += ft_ptrnbr_base((nbr / base_len), base, fd);
	i += ft_putchar(base[nbr % base_len], fd);
	return (i);
}

int	ft_ptrnbr(void *ptr, int fd)
{
	int		i;

	if (ptr == NULL)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	i = ft_putstr("0x", fd);
	i += ft_ptrnbr_base((unsigned long)ptr, "0123456789abcdef", fd);
	return (i);
}
