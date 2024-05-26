/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:30 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/26 17:04:46 by joneves-         ###   ########.fr       */
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
	int		nbr;

}	t_lflags;

/* New funticions */

/* Convert unsinged integer to hexadecimal in a string */
char		*ft_uitoa_hex(unsigned int n);
/* Convert unsinged integer to a string */
char		*ft_uitoa(unsigned int n);
/* Convert pointer to hexadecimal in a string with '0x' */
char		*ft_ptoa(unsigned long n);

/* Utils ft_printf*/

int			ft_checklen(char *str, char fmt);
char		*ft_merge(char *s1, char *s2, int fmt);

/* Utils ft_printf_bonus 'format'*/

int			ft_flaglen(char *str);
void		lflag_clear(t_lflags *lstflags);
t_lflags	ft_flagchr(t_lflags *lstflags, char flag, int mode);
char		*ft_multichar(char c, int nbr);
char		ft_getfmt(char *str);

/* Write a library that contains ft_printf(), a
function that will mimic the original printf() */
int			ft_printf(const char *format, ...);
char		*ft_format(va_list args, const char fmt);

/* New funticions BONUS*/

char		*ft_parserflags(char *flags, va_list args);
char		*ft_fmtspecifiers(char *str, t_lflags *lstflags, char f);
char		*ft_add_precision(char *str, char fmt, t_lflags flag);

#endif //FT_PRINTF_BONUS_H