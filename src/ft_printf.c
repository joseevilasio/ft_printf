/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:33:57 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/24 17:49:12 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char fmt)
{
	int	i;

	i = 0;
	if (fmt == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (fmt == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (fmt == 'p')
		i += ft_putpointer(va_arg(args, unsigned long long));
	else if (fmt == 'd' || fmt == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (fmt == 'u')
		i += ft_putunsignednbr(va_arg(args, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		i += ft_putnbrhex(va_arg(args, unsigned int), fmt);
	else if (fmt == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	char	*ptr_str;

	ptr_str = (char *) str;
	len = 0;
	va_start(args, str);
	while (*ptr_str)
	{
		if (*ptr_str == '%')
		{
			ptr_str++;
			len += ft_format(args, *ptr_str);
		}
		else
			len += ft_putchar(*ptr_str);
		ptr_str++;
	}
	va_end(args);
	return (len);
}
