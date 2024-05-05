/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:38:55 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 23:57:59 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (*str)
		{
			ft_putchar_fd(*str, 1);
			i++;
			str++;
		}
	}
	else
		i += ft_putstr("(null)");
	return (i);
}

int	ft_putunsignednbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putunsignednbr(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
		i++;
	}
	else
	{
		ft_putchar_fd(n % 10 + '0', 1);
		i++;
	}
	return (i);
}

int	ft_putnbrhex(unsigned int n, char fmt)
{
	char	c;
	int		i;

	i = 0;
	if (fmt == 'x')
		c = 'a';
	if (fmt == 'X')
		c = 'A';
	if (n >= 16)
		i += ft_putnbrhex(n / 16, fmt);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += c - 10;
	ft_putchar_fd(n, 1);
	i++;
	return (i);
}

static int	putpointer(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += putpointer(n / 16);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += 'a' - 10;
	ft_putchar_fd(n, 1);
	i++;
	return (i);
}

int	ft_putpointer(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0 || NULL)
		i += ft_putstr("(nil)");
	else
	{
		i += ft_putstr("0x");
		i += putpointer(n);
	}
	return (i);
}
