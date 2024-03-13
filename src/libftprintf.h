/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:21:55 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/13 20:34:15 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

/* Write a library that contains ft_printf(), a
function that will mimic the original printf() */
int		ft_printf(const char *format, ...);

/* Outputs the integer in hexadecimal lowercase ’n’ to the given file
descriptor. */
void	ft_putnbrhex_fd(int n, int fd);

/* Outputs the integer in hexadecimal uppercase ’n’ to the given file
descriptor. */
void	ft_putnbrhex_upper_fd(int n, int fd);

/* Outputs the decimal ’n’ to the given file descriptor. */
void	ft_putdecimal_fd(float n, int fd);

#endif //LIBFTPRINTF_H
