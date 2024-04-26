/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:06:41 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/26 20:06:43 by joneves-         ###   ########.fr       */
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
