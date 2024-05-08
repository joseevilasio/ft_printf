/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:30 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/07 23:22:20 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct t_lflags
{
	char	flag;
	char	type;
	t_bool	use;
	int		number;

}	t_lflags;

/* New funticions */

/* Convert unsinged integer to hexadecimal in a string */
char	*ft_uitoa_hex(unsigned int n);
/* Convert unsinged integer to a string */
char	*ft_uitoa(unsigned int n);
/* Convert pointer to hexadecimal in a string with '0x' */
char	*ft_ptoa(unsigned long n);

/* Utils */

int		ft_checklen(char *str, char fmt);
int		ft_flaglen(char *str);
void	lflag_clear(t_lflags *lstflags);
t_bool	ft_flagchr(t_lflags *lstflags, char flag);

/* Write a library that contains ft_printf(), a
function that will mimic the original printf() */
int		ft_printf(const char *format, ...);
char	*ft_format(va_list args, const char fmt);

/* New funticions BONUS*/

char	*ft_parserflags(char *flags, va_list args);
char	*ft_fmtspecifiers(char *str, t_lflags *lstflags, char f);

#endif //FT_PRINTF_BONUS_H