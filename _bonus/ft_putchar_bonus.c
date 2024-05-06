/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:24 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 23:43:08 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar_bonus(int c, t_listflag *lflags, int n)
{
	int	i;

	i = 0;
	if (ft_isflag('-', lflags))
	{
		ft_putchar_fd(c, 1);
		i++;
		i += ft_putnchar_bonus(' ', n - i);
	}
	else if (ft_isflag('n', lflags))
	{
		i += ft_putnchar_bonus(' ', (n - 1));
		ft_putchar_fd(c, 1);
		i++;
	}
	else
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
