/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:21:55 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/22 17:21:27 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include "bonus/ft_printf_bonus.h"
# include <stdio.h>
# include <stdlib.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbrhex(unsigned int n, char fmt);
int	ft_putunsignednbr(unsigned int n);
int	ft_putpointer(unsigned long long n);
/* Write a library that contains ft_printf(), a
function that will mimic the original printf() */
int	ft_printf(const char *format, ...);

#endif //FT_PRINTF_H
