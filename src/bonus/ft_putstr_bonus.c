/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:06:31 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/01 00:07:41 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	strlen_(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

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

int	ft_putstr_bonus(char *str, t_listflag *lflags, int n)
{
	int	i;
	int	len;

	i = 0;
	len = strlen_(str);
	if (ft_isflag('.', lflags))
		i += putnstr(str, n);
	else if (ft_isflag('-', lflags))
	{
		i += putnstr(str, len);
		i += ft_putnchar_bonus(' ', n - i);
	}
	else if (ft_isflag('n', lflags))
	{
		i += ft_putnchar_bonus(' ', (n - len));
		i += putnstr(str, len);
	}
	else
		i += putnstr(str, len);	
	return (i);
}
