/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:33:57 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/20 18:07:26 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			len += ft_flags(ptr_str, args);
			if (ft_length_flags(ptr_str) != 0)
				ptr_str += ft_length_flags(ptr_str);
		}
		else
			len += ft_putchar(*ptr_str);
		ptr_str++;
	}
	va_end(args);
	return (len);
}
