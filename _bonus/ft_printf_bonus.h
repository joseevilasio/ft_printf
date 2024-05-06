/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:30 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/05 15:23:15 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct t_listflag
{
	char	flag;
	t_bool	exe;

}	t_listflag;

/* Write a library that contains ft_printf(), a
function that will mimic the original printf() */
int	ft_printf(const char *format, ...);

/* FTS FOR BONUS */

int	ft_parserflag(char *str, va_list args, t_listflag **lflags, char **n);
int	ft_length_flags(char *str);
int	ft_isflag(char flag, t_listflag *lflags);
int	ft_putnchar_bonus(int c, int n);
int	ft_putstr_bonus(char *str, t_listflag *lflags, int n);
int	ft_putchar_bonus(int c, t_listflag *lflags, int n);
int	ft_putnbr_bonus(int n, t_listflag *lflags, int nbr);
int	ft_putpointer_bonus(unsigned long long n, t_listflag *lflags, int nbr);
int	ft_putnbrhex_bonus(unsigned int n, char fmt, t_listflag *lflags, int nbr);
int	ft_putunsignednbr_bonus(unsigned int n, t_listflag *lflags, int nbr);

#endif //FT_PRINTF_H