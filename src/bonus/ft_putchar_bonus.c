/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:02:43 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/30 19:26:20 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar_bonus(int c, t_listflag *lflags, int n)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (lflags[a].flag)
	{
		if (lflags[a].flag == '-' && lflags[a].exe == TRUE)
		{
			i += ft_putchar(c);
			i += ft_putnchar_bonus(' ', n - i);
		}
		a++;
	}
	if (n > 0 && i == 0)
		i += ft_putnchar_bonus(' ', (n - 1));
	if (lflags[0].flag == 0)
		i += ft_putchar(c);
	return (i);
}
