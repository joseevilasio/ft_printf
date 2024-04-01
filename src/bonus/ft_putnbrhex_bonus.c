/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:25 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/01 11:16:41 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	intlen_bonus(unsigned int n)
{
	int				i;
	unsigned int	s;

	i = 0;
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

static char	*putnbrhex_bonus(unsigned int n, char fmt)
{
	char			*str;
	char			c;
	int				size;
	unsigned int	s;

	size = intlen_bonus(n);
	c = 'a';
	str = (char *) malloc(size * sizeof(char) + 1);
	if (str)
	{
		if (fmt == 'X')
			c = 'A';
		str[size] = '\0';
		while (size-- > 0 && n != 0)
		{
			s = n % 16;
			if (s < 10)
				str[size] = s + '0';
			else
				str[size] = s + c - 10;
			n = n / 16;
		}
	}
	return (str);
}

int	ft_putnbrhex_bonus(unsigned int n, char fmt, t_listflag *lflags, int nbr)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_isflag('#', lflags) && fmt == 'x')
		i += ft_putstr("0x");
	if (ft_isflag('#', lflags) && fmt == 'X')
		i += ft_putstr("0X");
	str = putnbrhex_bonus(n, fmt);
	i += ft_putstr_bonus(str, lflags, nbr - i);
	free(str);
	return (i);
}
