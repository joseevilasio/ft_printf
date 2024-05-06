/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:14 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 23:46:37 by joneves-         ###   ########.fr       */
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
		i += ft_putstr("2147483648");
	}
	else if (n < 0)
	{
		i += putnbr_bonus(-n);
	}
	else if (n > 9)
	{
		i += putnbr_bonus(n / 10);
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

static int	put_before(int n, t_listflag *lflags, int nbr)
{
	int	i;

	i = 0;
	if (ft_isflag('0', lflags) == 1 || ft_isflag('.', lflags) == 1)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			i++;			
		}
		else if (ft_isflag('+', lflags) == 1)
		{
			ft_putchar_fd('+', 1);
			i++;			
		}
		if (ft_isflag('.', lflags) == 1 && (n < 0))
			i += ft_putnchar_bonus('0', nbr - (intlen_bonus(n) + i - 1));
		else
			i += ft_putnchar_bonus('0', nbr - (intlen_bonus(n) + i));
	}
	else
	{
		if (ft_isflag('+', lflags) == 1 || n < 0)
			i++;
		i += ft_putnchar_bonus(' ', nbr - (intlen_bonus(n) + i));
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			i++;			
		}
		else if (ft_isflag('+', lflags) == 1)
		{
			ft_putchar_fd('+', 1);
			i++;			
		}
	}
	return (i);
}

static int	put_after(int n, t_listflag *lflags, int nbr)
{
	int	i;

	i = 0;
	if (ft_isflag(' ', lflags) == 1)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
	}
	if (ft_isflag('+', lflags) == 1)
	{
		ft_putchar_fd('+', 1);
		i++;
	}
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
	else if (lflags[0].flag)
	{
		if (ft_isflag(' ', lflags) == 1)
			i += ft_putchar(' ');
		i += put_before(n, lflags, nbr - i);
		i += putnbr_bonus(n);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			i++;			
		}
		i += putnbr_bonus(n);
	}
	return (i);
}
