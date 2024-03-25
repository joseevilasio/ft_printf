/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:06:31 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/25 23:28:54 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	putnstr(char *str, int n)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (*str && n-- > 0)
		{
			i += ft_putchar(*str);
			str++;
		}
	}
	else
		i += putnstr("(nil)", 5);
	return (i);
}

int	ft_putstr_bonus(char *str, char flag, int n)
{
	int	i;
	int	len;

	i = 0;
	if (str == NULL)
		len = 0;
	else
		len = ft_strlen(str);
	if (flag == '.')
		i += putnstr(str, n);
	else if (flag == '-')
	{
		i += putnstr(str, len);
		i += ft_putnchar_bonus(' ', n - i);
	}
	else if (flag == 'n' && n > 0)
	{
		i += ft_putnchar_bonus(' ', (n - len));
		i += putnstr(str, len);
	}
	else
		i += putnstr(str, len);
	return (i);
}
