/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:33:57 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/22 17:25:34 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_bonus(const char *str, ...)
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
	while (*ptr_str)
	{
		if (*ptr_str == '%')
		{
			ptr_str++;
			ft_parserflag(ptr_str, args, l_flags, &n);
			ptr_str += ft_length_flags(ptr_str);
			len += ft_format_bonus(args, *ptr_str, l_flags, ft_atoi(n));
		}
		else
			len += ft_putchar(*ptr_str);
		ptr_str++;
	}
	va_end(args);
	return (len);
}
