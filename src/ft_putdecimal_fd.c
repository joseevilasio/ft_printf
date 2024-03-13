/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:13:54 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/13 20:33:42 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putdecimal_fd(float n, int fd)
{	
	int		integer;
	int		integer_swap;
	float	decimal;

	integer = n;
	ft_putnbr_fd(integer, fd);
	if (n < 0)
	{
		integer = integer * (-1);
		n = n * (-1);
		decimal = (integer - n) * integer;
	}
	else
		decimal = (integer - n) * integer;
	integer_swap = decimal;
	ft_putchar_fd('.', fd);
	ft_putnbr_fd(integer_swap, fd);
}
