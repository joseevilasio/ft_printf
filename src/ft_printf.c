/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:38 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 23:23:37 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(int c)
{
	write(1, &c, sizeof(char));
	return (1);
}

static int	ft_putnbr(char *nbr)
{
	int	i;

	i = 0;
	i += ft_putstr(nbr);
	free(nbr);
	return (i);
}

static int	ft_format(va_list args, const char fmt)
{
	int		i;

	i = 0;
	if (fmt == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (fmt == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (fmt == 'p')
		i += ft_putpointer(va_arg(args, unsigned long));
	else if (fmt == 'd' || fmt == 'i')
		i += ft_putnbr(ft_itoa(va_arg(args, int)));
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
