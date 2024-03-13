/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:33:57 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/13 20:37:38 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// static int	count_args(const char *str)
// {
// 	char	*ptr_str;
// 	int		i;

// 	ptr_str = (char *) str;
// 	i = 0;
// 	while(*ptr_str != '\0')
// 	{
// 		if (*ptr_str == '%')
// 			i++;
// 		ptr_str++;
// 	}
// 	return (i);
// }

// static void	print(char c, void *item)
// {
// 	// int		arg_int;
// 	// char	*arg_str;

// 	if (c == 'c')
// 		ft_putchar_fd(item, 1);
// 	else if (c == 's')
// 		ft_putstr_fd(item, 1);
// 	// else if (c == 'p')
// 	// else if (c == 'd')
// 	else if (c == 'i')
// 		ft_putnbr_fd(item, 1);
// 	// else if (c == 'u')
// 	// else if (c == 'c')
// 	// else if (c == 'x')
// 	// else if (c == 'X')
// 	// else if (c == '%')
// }

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;

	str = (char *) format;
	va_start(args, format);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (*str == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (*str == 'p')
				ft_putnbrhex_fd(va_arg(args, int), 1);
			else if (*str == 'd')
				ft_putdecimal_fd(va_arg(args, float), 1);
			else if (*str == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			// else if (*str == 'u')
			else if (*str == 'x')
				ft_putnbrhex_fd(va_arg(args, int), 1);
			else if (*str == 'X')
				ft_putnbrhex_upper_fd(va_arg(args, int), 1);
			else if (*str == '%')
				ft_putchar_fd('%', 1);
		}
		str++;
	}
	va_end(args);
	return (0);
}
