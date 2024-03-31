/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:02:43 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/01 00:11:20 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
