/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:21:55 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/21 15:46:49 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef enum t_bool { FALSE, TRUE }	t_bool;
typedef struct t_listflag
{
	char	flag;
	t_bool	execute;

}	t_listflag;

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbrhex(unsigned int n, char fmt);
int	ft_putunsignednbr(unsigned int n);
int	ft_putpointer(unsigned long long n);
/* Write a library that contains ft_printf(), a
function that will mimic the original printf() */
int	ft_printf(const char *format, ...);

/* BONUS */
int	ft_flags(char *str, va_list args);
int	ft_length_flags(char *str);
int	ft_putnchar(int c, int n);
int	ft_format(va_list args, const char fmt, t_listflag *list_flags, int nbr);

#endif //FT_PRINTF_H
