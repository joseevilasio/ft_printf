/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:25 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/15 15:05:26 by josejunior       ###   ########.fr       */
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
	i += ft_putstr("0x");
	if (n == 0)
		i += ft_putchar('0');
	else
		i += putpointer(n);
	return (i);
}
