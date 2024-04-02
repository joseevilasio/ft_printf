/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:25 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/02 13:58:03 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	intlen_bonus(unsigned int n)
{
	int				i;
	unsigned int	s;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		s = n % 16;
		if (s < 10)
			i++;
		else
			i++;
		n = n / 16;
	}
	return (i);
}

static int	putnbrhex_bonus(unsigned int n, char fmt)
{
	char	c;
	int		i;

	i = 0;
	if (fmt == 'x')
		c = 'a';
	if (fmt == 'X')
		c = 'A';
	if (n >= 16)
		i += putnbrhex_bonus(n / 16, fmt);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += c - 10;
	i += ft_putchar(n);
	return (i);
}

static int	put_before(int n, t_listflag *lflags, int nbr, char fmt)
{
	int	i;

	i = 0;
	if (ft_isflag(' ', lflags) == 1)
		i += ft_putchar(' ');
	if (ft_isflag('#', lflags) && fmt == 'x' && n != 0)
		i += ft_putstr("0x");
	if (ft_isflag('#', lflags) && fmt == 'X' && n != 0)
		i += ft_putstr("0X");
	if (ft_isflag('0', lflags) == 1 || ft_isflag('.', lflags) == 1)
		i += ft_putnchar_bonus('0', nbr - (intlen_bonus(n) + i));
	else if (ft_isflag('n', lflags) == 1)
		i += ft_putnchar_bonus(' ', nbr - (intlen_bonus(n) + i));
	i += putnbrhex_bonus(n, fmt);
	return (i);
}

static int	put_after(int n, t_listflag *lflags, int nbr, char fmt)
{
	int	i;

	i = 0;
	if (ft_isflag(' ', lflags) == 1)
		i += ft_putchar(' ');
	if (ft_isflag('#', lflags) && fmt == 'x' && n != 0)
		i += ft_putstr("0x");
	if (ft_isflag('#', lflags) && fmt == 'X' && n != 0)
		i += ft_putstr("0X");
	i += putnbrhex_bonus(n, fmt);
	if (ft_isflag('-', lflags) == 1)
		i += ft_putnchar_bonus(' ', nbr - i);
	return (i);
}

int	ft_putnbrhex_bonus(unsigned int n, char fmt, t_listflag *lflags, int nbr)
{
	int		i;

	i = 0;
	if (ft_isflag('-', lflags) == 1)
		i += put_after(n, lflags, nbr, fmt);
	else if (lflags[0].flag)
		i += put_before(n, lflags, nbr, fmt);
	else
		i += putnbrhex_bonus(n, fmt);	
	return (i);
}
