/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_nbrhexa_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:19:45 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/25 20:24:54 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	length_nbrhexa(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += length_nbrhexa(n / 16);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += 'a' - 10;
	i++;
	return (i);
}

int	ft_length_nbrhexa(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0 || NULL)
		i += ft_strlen("(nil)");
	else
	{
		i += ft_strlen("0x");
		i += length_nbrhexa(n);
	}
	return (i);
}
