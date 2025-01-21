/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:19:56 by musisman          #+#    #+#             */
/*   Updated: 2024/11/14 20:01:24 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flags(int c, va_list args, int fd)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int), fd));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), fd));
	else if (c == 'p')
		return (ft_ptrnbr(va_arg(args, void *), fd));
	else if (c == 'd')
		return (ft_putnbr_base(va_arg(args, int), "0123456789", fd));
	else if (c == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789",  fd));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", fd));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", fd));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", fd));
	else if (c == '%')
		return (ft_putchar('%', fd));
	else
		return (0);
}

int	ft_printf(int fd, const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += flags(s[i], args, fd);
		}
		else
			len += ft_putchar(s[i], fd);
		i++;
	}
	va_end(args);
	return (len);
}
