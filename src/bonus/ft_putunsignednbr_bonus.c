/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:25 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/01 19:22:35 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	intlen_bonus(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += intlen_bonus(n / 10);
		i++;
	}
	else
		i++;
	return (i);
}

static int	putunsignednbr_bonus(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += putunsignednbr_bonus(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_putunsignednbr_bonus(unsigned int n, t_listflag *lflags, int nbr)
{
	int	i;

	i = 0;
	if (ft_isflag('-', lflags) == 1)
	{
		i += putunsignednbr_bonus(n);
		if (ft_isflag('-', lflags) == 1)
			i += ft_putnchar_bonus(' ', nbr - i);
	}
	else
	{
		if (ft_isflag('0', lflags) == 1 || ft_isflag('.', lflags) == 1)
			i += ft_putnchar_bonus('0', nbr - intlen_bonus(n));
		else if (ft_isflag('n', lflags) == 1)
			i += ft_putnchar_bonus(' ', nbr - intlen_bonus(n));
		i += putunsignednbr_bonus(n);
	}
	return (i);
}
