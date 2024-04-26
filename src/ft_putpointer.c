/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:06:23 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/26 20:06:25 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putpointer(unsigned long long n)
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
	i += ft_putchar(n);
	return (i);
}

int	ft_putpointer(unsigned long long n)
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
