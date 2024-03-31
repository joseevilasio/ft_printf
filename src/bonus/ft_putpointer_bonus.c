/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:25 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/31 21:13:47 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	pointerlen_bonus(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += pointerlen_bonus(n / 16);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += 'a' - 10;
	i++;
	return (i);
}

static int	putpointer_bonus(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += putpointer_bonus(n / 16);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += 'a' - 10;
	i += ft_putchar(n);
	return (i);
}

int	ft_putpointer_bonus(unsigned long long n, t_listflag *lflags, int nbr)
{
	int	i;

	i = 0;
	if (n && ft_isflag('n', lflags) == 1)
	{
		i += ft_putnchar_bonus(' ', nbr - (pointerlen_bonus(n) + 2));
		i += ft_putstr("0x");
		i += putpointer_bonus(n);
	}
	else
	{
		i += ft_putnchar_bonus(' ', nbr - 5);
		i += ft_putstr("(nil)");
	}
	return (i);
}