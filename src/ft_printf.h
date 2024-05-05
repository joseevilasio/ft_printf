/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:30 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/05 19:01:22 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

/* New funticions */

char	*ft_uitoa_hex(unsigned int n);
char	*ft_uitoa(unsigned int n);
char	*ft_ptoa(unsigned long n);

/* Utils */

int		ft_checklen(char *str, char fmt);

/* Write a library that contains ft_printf(), a
function that will mimic the original printf() */
int		ft_printf(const char *format, ...);

#endif //FT_PRINTF_H