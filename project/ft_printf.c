/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:44:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/22 14:10:57 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[count] != '\0')
		{
			write (1, &str[count], 1);
			count++;
		}
		return (count);
	}
}

static int	ft_putnbr(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

static int	ft_format(va_list ap, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (type == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (type == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		symbols;

	count = 0;
	symbols = 0;
	va_start(ap, s);
	while (s[count])
	{
		if (s[count] == '%')
			symbols += ft_format(ap, s[++count]);
		else
			symbols += ft_putchar(s[count]);
		count++;
	}
	va_end(ap);
	return (symbols);
}
