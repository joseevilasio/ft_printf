/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:06:36 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/26 20:06:37 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar_bonus(int c, int n)
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
