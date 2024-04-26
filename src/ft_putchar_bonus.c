/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:24 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/26 20:07:25 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_bonus(int c, t_listflag *lflags, int n)
{
	int	i;

	i = 0;
	if (ft_isflag('-', lflags))
	{
		i += ft_putchar(c);
		i += ft_putnchar_bonus(' ', n - i);
	}
	else if (ft_isflag('n', lflags))
	{
		i += ft_putnchar_bonus(' ', (n - 1));
		i += ft_putchar(c);
	}
	else
		i += ft_putchar(c);
	return (i);
}
