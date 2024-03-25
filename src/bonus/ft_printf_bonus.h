/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:11:37 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/25 22:09:28 by josejunior       ###   ########.fr       */
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
	t_bool	execute;

}	t_listflag;

int	ft_parserflag(char *str, va_list args, t_listflag **l_flags, char **n);
int	ft_length_flags(char *str);
int	ft_putnchar_bonus(int c, int n);
int	ft_format_bonus(va_list args, const char fmt, t_listflag *l_flags, int nbr);
int	ft_printf(const char *str, ...);
int	ft_length_nbrhexa(unsigned long long n);
int	ft_putstr_bonus(char *str, char flag, int n);

#endif //FT_PRINTF_BONUS_H
