/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:25 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/15 15:10:09 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	i += ft_putchar(n);
	return (i);
}
