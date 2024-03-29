/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:02:43 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/22 17:14:35 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnchar(int c, int n)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
			i += ft_putchar(c);
	}
	return (i);
}
