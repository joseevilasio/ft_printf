/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:38 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/26 11:11:30 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	fmtupper(char *specifier)
{
	int	i;

	i = 0;
	while (specifier[i])
	{
		specifier[i] = ft_toupper(specifier[i]);
		i++;
	}
}

static char	*str_check(char *specifier)
{
	if (!specifier)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(specifier));
}

static char	*ctoa(int c)
{
	char	*str;

	if (c == 0)
	{
		ft_putchar_fd(c, 1);
		return (NULL);
	}
	str = (char *) malloc(2 * sizeof(char));
	str[0] = (char) c;
	str[1] = '\0';
	return (str);
}

char	*ft_format(va_list args, const char fmt)
{
	char	*specifier;

	if (fmt == 'c')
		specifier = ctoa(va_arg(args, int));
	else if (fmt == 's')
		specifier = str_check(va_arg(args, char *));
	else if (fmt == 'p')
		specifier = ft_ptoa(va_arg(args, unsigned long));
	else if (fmt == 'd' || fmt == 'i')
		specifier = ft_itoa(va_arg(args, int));
	else if (fmt == 'u')
		specifier = ft_uitoa(va_arg(args, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
	{
		specifier = ft_uitoa_hex(va_arg(args, unsigned int));
		if (fmt == 'X')
			fmtupper(specifier);
	}
	else if (fmt == '%')
		specifier = ft_strdup("%");
	return (specifier);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		number_of_char;
	char	*fmt_specifier;

	number_of_char = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			fmt_specifier = ft_parserflags((char *)(++str), args);
			number_of_char += ft_checklen(fmt_specifier, *str);
			ft_putstr_fd(fmt_specifier, 1);
			free(fmt_specifier);
			str = ft_strchr((char *)str, ft_getfmt((char *)str));
		}
		else
		{
			ft_putchar_fd(*str, 1);
			number_of_char++;
		}
		str++;
	}
	va_end(args);
	return (number_of_char);
}
