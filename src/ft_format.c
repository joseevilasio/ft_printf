/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:49:21 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/21 15:18:31 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putzero_space(va_list copy_args, char fmt, int nbr, char flag)
{
	int		len;
	int		i;
	char	*s;

	len = 0;
	i = 0;
	if (flag == '0')
	{
		len = ft_strlen(ft_itoa(va_arg(copy_args, int)));
		i += ft_putnchar('0', nbr - len);
	}
	if (flag == 'a')
	{
		if (fmt == 's')
		{
			s = va_arg(copy_args, char *);
			if (s)
				len = ft_strlen(s);
		}
		else
			len = 1;
		i += ft_putnchar(' ', nbr - len);
	}
	return (i);
}

static int	format_execute(va_list args, const char fmt, char flag, int nbr)
{
	int		i;
	va_list	copy_args;

	i = 0;
	va_copy(copy_args, args);
	if (flag == '0' || flag == 'a')
		i += putzero_space(copy_args, fmt, nbr, flag);
	if (fmt == 'c')
		i += ft_putchar(va_arg(args, int));
	if (fmt == 's')
		i += ft_putstr(va_arg(args, char *));
	if (fmt == 'p')
		i += ft_putpointer(va_arg(args, unsigned long long));
	if (fmt == 'd' || fmt == 'i')
		i += ft_putnbr(va_arg(args, int));
	if (fmt == 'u')
		i += ft_putunsignednbr(va_arg(args, unsigned int));
	if (fmt == 'x' || fmt == 'X')
		i += ft_putnbrhex(va_arg(args, unsigned int), fmt);
	if (fmt == '%')
		i += ft_putchar('%');
	if (flag == '-')
		i += ft_putnchar(' ', nbr - i);
	return (i);
}

int	ft_format(va_list args, const char fmt, t_listflag *l_flags, int nbr)
{
	int		i;
	int		a;
	char	flag;

	a = 0;
	i = 0;
	flag = 'a';
	while (l_flags[a].flag)
	{
		if (l_flags[a].flag == '#' && l_flags[a].execute == TRUE && fmt == 'x')
			i += ft_putstr("0x");
		if (l_flags[a].flag == '#' && l_flags[a].execute == TRUE && fmt == 'X')
			i += ft_putstr("0X");
		else if (l_flags[a].flag == '+' && l_flags[a].execute == TRUE)
			i += ft_putchar('+');
		else if (l_flags[a].flag == ' ' && l_flags[a].execute == TRUE)
			i += ft_putchar(' ');
		else if (l_flags[a].flag == '0' && l_flags[a].execute == TRUE)
			flag = '0';
		else if (l_flags[a].flag == '-' && l_flags[a].execute == TRUE)
			flag = '-';
		a++;
	}
	i += format_execute(args, fmt, flag, nbr - i);
	return (i);
}
