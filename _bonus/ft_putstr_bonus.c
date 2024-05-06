/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:06:16 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 23:48:33 by joneves-         ###   ########.fr       */
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
			ft_putchar_fd(*str, 1);
			i++;
			str++;
		}
	}
	else
		i += putnstr("(null)", 6);
	return (i);
}

int	ft_putstr_bonus(char *str, t_listflag *lflags, int n)
{
	int	i;
	int	len;

	i = 0;
	len = strlen_(str);
	if (ft_isflag('.', lflags) == 1)
		i += putnstr(str, n);
	else if (ft_isflag('-', lflags) == 1)
	{
		i += putnstr(str, len);
		i += ft_putnchar_bonus(' ', n - i);
	}
	else if (ft_isflag('n', lflags) == 1)
	{
		i += ft_putnchar_bonus(' ', (n - len));
		i += putnstr(str, len);
	}
	else
		i += putnstr(str, len);
	return (i);
}
