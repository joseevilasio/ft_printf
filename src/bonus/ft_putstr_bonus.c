/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:06:31 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/26 23:45:16 by josejunior       ###   ########.fr       */
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

int	ft_putstr_bonus(char *str, t_listflag *l_flags, int n)
{
	int	i;
	int	len;
	int	a;

	i = 0;
	a = 0;
	len = strlen_(str);
	while (l_flags[a].flag)
	{
		if (l_flags[a].flag == '.' && l_flags[a].execute == TRUE)
			i += putnstr(str, n);
		else if (l_flags[a].flag == '-' && l_flags[a].execute == TRUE)
		{
			i += putnstr(str, len);
			i += ft_putnchar_bonus(' ', n - i);
		}
		a++;
	}
	if (n > 0 && i == 0)
		i += ft_putnchar_bonus(' ', (n - len));
	if (l_flags[0].flag == 0)
		i += putnstr(str, len);
	return (i);
}
