/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtspecifiers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:18:24 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/26 17:04:36 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*add_prefix(char *str, char fmt, t_lflags flag)
{
	char	*new_str;

	if (flag.flag == '#' && flag.use == TRUE)
	{
		if (fmt == 'x')
			new_str = ft_merge("0x", str, fmt);
		else
			new_str = ft_merge("0X", str, fmt);
	}
	else if (flag.flag == '+' && flag.use == TRUE)
		new_str = ft_merge("+", str, fmt);
	else if (flag.flag == ' ' && flag.use == TRUE)
		new_str = ft_merge(" ", str, fmt);
	else
		return (str);
	return (new_str);
}

static char	*add_width(char *str, char fmt, t_lflags flag)
{
	char	*new_str;
	char	*width;
	int		size_str;

	size_str = ft_strlen(str);
	if (flag.nbr > size_str && flag.use == TRUE)
	{
		if (flag.flag == 'n' || flag.flag == '-')
			width = ft_multichar(' ', flag.nbr - size_str);
		else
			width = ft_multichar('0', flag.nbr - size_str);
		if (flag.flag == '-')
		{
			new_str = ft_merge(str, width, fmt);
			free(str);
		}
		else
		{
			new_str = ft_merge(width, str, fmt);
			free(width);
		}
	}
	else
		return (str);
	return (new_str);
}

static char	*width(char *str, t_lflags *lflags, char fmt, int indice)
{
	if (ft_flagchr(lflags, 'p', 2).flag)
		str = ft_add_precision(str, fmt, ft_flagchr(lflags, 'p', 2));
	if (ft_flagchr(lflags, '-', 1).flag || ft_flagchr(lflags, 'n', 1).flag)
		str = add_prefix(str, fmt, ft_flagchr(lflags, 'a', 2));
	str = add_width(str, fmt, lflags[indice]);
	if (!ft_flagchr(lflags, '-', 1).flag && !ft_flagchr(lflags, 'n', 1).flag)
		str = add_prefix(str, fmt, ft_flagchr(lflags, 'a', 2));
	return (str);
}

char	*ft_fmtspecifiers(char *str, t_lflags *lflags, char fmt)
{
	int		a;
	char	*specifier;

	a = 0;
	specifier = str;
	while (lflags[a].flag)
	{
		if (lflags[a].type == 'a' && !ft_flagchr(lflags, 'w', 2).flag
			&& !ft_flagchr(lflags, 'p', 2).flag)
			specifier = add_prefix(specifier, fmt, lflags[a]);
		else if (lflags[a].type == 'p' && !ft_flagchr(lflags, 'w', 2).flag)
		{
			specifier = ft_add_precision(specifier, fmt, lflags[a]);
			specifier = add_prefix(specifier, fmt, ft_flagchr(lflags, 'a', 2));
		}
		else if (lflags[a].type == 'w')
		{
			specifier = width(specifier, lflags, fmt, a);
		}
		a++;
	}
	return (specifier);
}
