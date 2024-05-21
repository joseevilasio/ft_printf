/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtspecifiers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:18:24 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/21 22:20:32 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*merge(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	free(s2);
	return (new);
}

static char	*add_prefix(char *str, char fmt, t_lflags lstflags)
{
	char	*new_str;

	if (lstflags.flag == '#' && lstflags.use == TRUE)
	{
		if (fmt == 'x')
			new_str = merge("0x", str);
		else
			new_str = merge("0X", str);
	}
	else if (lstflags.flag == '+' && lstflags.use == TRUE)
		new_str = merge("+", str);
	else if (lstflags.flag == ' ' && lstflags.use == TRUE)
		new_str = merge(" ", str);
	else
		return (str);
	return (new_str);
}

static char	*add_width(char *str, t_lflags lstflags)
{
	char	*new_str;
	char	*width;
	int		size_str;

	size_str = ft_strlen(str);
	if (lstflags.number > size_str && lstflags.use == TRUE)
	{
		if (lstflags.flag == 'n' || lstflags.flag == '-')
			width = ft_multichar(' ', lstflags.number - size_str);
		else
			width = ft_multichar('0', lstflags.number - size_str);
		if (lstflags.flag == '-')
		{
			// if ((fmt == 'd' || fmt == 'i') && ft_strchr(str, '-')) //negative
			new_str = merge(str, width);
			free(str);
		}
		else
		{
			new_str = merge(width, str);
			free(width);
		}
	}
	else
		return (str);
	return (new_str);
}

static char	*add_precision(char *str, char fmt, t_lflags lstflags)
{
	char	*new_str;
	char	*width;
	int		size_str;

	size_str = ft_strlen(str);
	if (lstflags.number < size_str && lstflags.use == TRUE && fmt == 's')
	{
		new_str = malloc((lstflags.number + 1) * sizeof(char));
		if (!new_str)
			return (NULL);
		ft_strlcpy(new_str, str, lstflags.number + 1);
		free(str);
	}
	else if (lstflags.number > size_str && lstflags.use == TRUE && fmt != 's')
	{
		width = ft_multichar('0', lstflags.number - size_str);
		new_str = merge(width, str);
		free(width);
	}
	else
		return (str);
	return (new_str);
}

char	*ft_fmtspecifiers(char *str, t_lflags *lflags, char fmt)
{
	int		a;
	char	*specifier;

	a = 0;
	specifier = str;
	while (lflags[a].flag)
	{
		if (lflags[a].type == 'a' && !ft_flagchr(lflags, 'w', 2).flag && !ft_flagchr(lflags, 'w', 2). flag)
			specifier = add_prefix(specifier, fmt, lflags[a]);
		else if (lflags[a].type == 'p')
		{
			specifier = add_precision(specifier, fmt, lflags[a]);
			specifier = add_prefix(specifier, fmt, ft_flagchr(lflags, 'a', 2));
		}
		else if (lflags[a].type == 'w')
		{
			if (ft_flagchr(lflags, '-', 1).flag || ft_flagchr(lflags, 'n', 1).flag)
				specifier = add_prefix(specifier, fmt, ft_flagchr(lflags, 'a', 2));
			specifier = add_width(specifier, lflags[a]);
			if (!ft_flagchr(lflags, '-', 1).flag && !ft_flagchr(lflags, 'n', 1).flag)
				specifier = add_prefix(specifier, fmt, ft_flagchr(lflags, 'a', 2));		
		}
		a++;
	}
	return (specifier);
}
