/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:33:57 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/24 20:29:13 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	fmt_printf(char *ptr_str, t_listflag *l_flags, va_list args, char *n)
{
	int	i;

	i = 0;
	while (*ptr_str)
	{
		if (*ptr_str == '%')
		{
			l_flags = NULL;
			n = NULL;
			ptr_str++;
			ft_parserflag(ptr_str, args, &l_flags, &n);
			ptr_str += ft_length_flags(ptr_str);
			i += ft_format_bonus(args, *ptr_str, l_flags, ft_atoi(n));
			free(n);
			free(l_flags);
		}
		else
			i += ft_putchar(*ptr_str);
		ptr_str++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_listflag	*l_flags;
	int			len;
	char		*ptr_str;
	char		*n;

	ptr_str = (char *) str;
	len = 0;
	l_flags = NULL;
	n = NULL;
	va_start(args, str);
	len += fmt_printf(ptr_str, l_flags, args, n);
	va_end(args);
	return (len);
}
