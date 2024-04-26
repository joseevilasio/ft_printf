/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:06:09 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/26 20:06:12 by joneves-         ###   ########.fr       */
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
