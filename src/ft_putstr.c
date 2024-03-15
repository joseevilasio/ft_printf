/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:06:31 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/15 14:27:16 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (*str)
		{
			i += ft_putchar(*str);
			str++;
		}
	}
	else
		i += ft_putstr("(null)");
	return (i);
}
