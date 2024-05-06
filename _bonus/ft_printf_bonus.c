/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 23:51:24 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	format_bonus(char fmt, t_listflag *lflags, va_list args, int n)
{
	int	i;

	i = 0;
	if (fmt == 'c')
		i += ft_putchar_bonus(va_arg(args, int), lflags, n);
	else if (fmt == 's')
		i += ft_putstr_bonus(va_arg(args, char *), lflags, n);
	else if (fmt == 'p')
		i += ft_putpointer_bonus(va_arg(args, unsigned long long), lflags, n);
	else if (fmt == 'd' || fmt == 'i')
		i += ft_putnbr_bonus(va_arg(args, int), lflags, n);
	else if (fmt == 'u')
		i += ft_putunsignednbr_bonus(va_arg(args, unsigned int), lflags, n);
	else if (fmt == 'x' || fmt == 'X')
		i += ft_putnbrhex_bonus(va_arg(args, unsigned int), fmt, lflags, n);
	else if (fmt == '%')
		i += ft_putchar_bonus('%', lflags, n);
	return (i);
}

static int	printf_bonus(char *str, t_listflag *lflags, va_list args, char *n)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			lflags = NULL;
			n = NULL;
			str++;
			ft_parserflag(str, args, &lflags, &n);
			str += ft_length_flags(str);
			i += format_bonus(*str, lflags, args, ft_atoi(n));
			free(n);
			free(lflags);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			i++;
		}
		str++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_listflag	*lflags;
	int			buffer;
	char		*ptr_str;
	char		*n;

	ptr_str = (char *) str;
	buffer = 0;
	lflags = NULL;
	n = NULL;
	va_start(args, str);
	buffer += printf_bonus(ptr_str, lflags, args, n);
	va_end(args);
	return (buffer);
}
