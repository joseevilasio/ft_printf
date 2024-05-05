/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:30 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/05 15:13:07 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

/* Utils */

int	ft_putstr(char *str);
int	ft_putnbrhex(unsigned int n, char fmt);
int	ft_putunsignednbr(unsigned int n);
int	ft_putpointer(unsigned long n);

/* Write a library that contains ft_printf(), a
function that will mimic the original printf() */
int	ft_printf(const char *format, ...);

#endif //FT_PRINTF_H