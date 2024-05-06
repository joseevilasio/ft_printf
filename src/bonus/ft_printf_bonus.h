/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:30 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/06 13:38:31 by joneves-         ###   ########.fr       */
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

typedef struct t_lflags
{
	char	flag;
	char	type;
	t_bool	use;

}	t_lflags;

/* New funticions */

char	*ft_uitoa_hex(unsigned int n);
char	*ft_uitoa(unsigned int n);
char	*ft_ptoa(unsigned long n);

/* Utils */

int		ft_checklen(char *str, char fmt);
int		ft_flaglen(char *str);
void	lflag_clear(t_lflags *lstflags);

/* Write a library that contains ft_printf(), a
function that will mimic the original printf() */
int		ft_printf(const char *format, ...);
char	*ft_format(va_list args, const char fmt);

/* New funticions BONUS*/

char	*ft_parserflags(char *flags, va_list args);
char	*ft_fmtspecifiers(char *str, t_lflags *lstflags, char f);

#endif //FT_PRINTF_H