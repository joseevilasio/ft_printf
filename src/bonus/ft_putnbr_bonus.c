/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:22:31 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/31 20:14:49 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	intlen_bonus(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i += ft_strlen("2147483648");
	else if (n < 0)
	{
		i += intlen_bonus(-n);
	}
	else if (n > 9)
	{
		i += intlen_bonus(n / 10);
		i++;
	}
	else
		i++;
	return (i);
}

static int	putnbr_bonus(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putchar('2');
		i += ft_putstr("147483648");
	}
	else if (n < 0)
	{
		i += putnbr_bonus(-n);
	}
	else if (n > 9)
	{
		i += putnbr_bonus(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n % 10 + '0');
	return (i);
}

static int	put_before(int n, t_listflag *lflags, int nbr)
{
	int	i;

	i = 0;
	if (ft_isflag(' ', lflags) == 1)
		i += ft_putchar(' ');
	if (ft_isflag('0', lflags) == 1)
	{
		if (n < 0)
			i += ft_putchar('-');
		else if (ft_isflag('+', lflags) == 1)
			i += ft_putchar('+');
		i += ft_putnchar_bonus('0', nbr - (intlen_bonus(n) + i));
	}
	else if (ft_isflag('n', lflags) == 1 || ft_isflag('.', lflags) == 1)
	{
		if (ft_isflag('+', lflags) == 1 || n < 0)
			i++;
		i += ft_putnchar_bonus(' ', nbr - (intlen_bonus(n) + i));
		if (n < 0)
			ft_putchar('-');
		else if (ft_isflag('+', lflags) == 1)
			ft_putchar('+');
	}
	i += putnbr_bonus(n);
	return (i);
}

static int	put_after(int n, t_listflag *lflags, int nbr)
{
	int	i;

	i = 0;
	if (ft_isflag(' ', lflags) == 1)
		i += ft_putchar(' ');
	if (n < 0)
		i += ft_putchar('-');
	if (ft_isflag('+', lflags) == 1)
		i += ft_putchar('+');
	i += putnbr_bonus(n);
	if (ft_isflag('-', lflags) == 1)
		i += ft_putnchar_bonus(' ', nbr - i);
	return (i);
}

int	ft_putnbr_bonus(int n, t_listflag *lflags, int nbr)
{
	int	i;

	i = 0;
	if (ft_isflag('-', lflags) == 1)
		i += put_after(n, lflags, nbr);
	else
		i += put_before(n, lflags, nbr);
	return (i);
}
