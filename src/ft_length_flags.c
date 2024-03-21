/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:32:34 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/20 18:01:54 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length_flags(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
			|| str[i] == '%')
			break ;
		i++;
	}
	return (i);
}
