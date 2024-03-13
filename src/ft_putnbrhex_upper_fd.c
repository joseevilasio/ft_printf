/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex_upper_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:51:05 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/13 18:51:30 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbrhex_upper_fd(int n, int fd)
{
	if (n >= 16)
		ft_putnbrhex_fd(n / 16, fd);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += 'A' - 10;
	ft_putchar_fd(n, fd);
}
