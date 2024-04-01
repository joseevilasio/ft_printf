/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:11:37 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/01 00:14:38 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include "../ft_printf.h"

typedef enum t_bool { FALSE, TRUE }	t_bool;
typedef struct t_listflag
{
	char	flag;
	t_bool	exe;

}	t_listflag;

int	ft_parserflag(char *str, va_list args, t_listflag **lflags, char **n);
int	ft_length_flags(char *str);
int	ft_printf(const char *str, ...);
int	ft_isflag(char flag, t_listflag *lflags);
/* Refactory fts for bonus */
int	ft_putnchar_bonus(int c, int n);
int	ft_putstr_bonus(char *str, t_listflag *lflags, int n);
int	ft_putchar_bonus(int c, t_listflag *lflags, int n);
int	ft_putnbr_bonus(int n, t_listflag *lflags, int nbr);
int	ft_putpointer_bonus(unsigned long long n, t_listflag *lflags, int nbr);
int	ft_putnbrhex_bonus(unsigned int n, char fmt, t_listflag *lflags, int nbr);
int	ft_putunsignednbr_bonus(unsigned int n, t_listflag *lflags, int nbr);

#endif //FT_PRINTF_BONUS_H
