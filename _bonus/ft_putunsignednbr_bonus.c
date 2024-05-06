/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:06:03 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 23:49:09 by joneves-         ###   ########.fr       */
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
