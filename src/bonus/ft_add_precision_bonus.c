/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_precision_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:41:21 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/26 17:09:56 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	size(char *str, char fmt)
{
	int	size_str;

	size_str = 0;
	if ((fmt == 'd' || fmt == 'i') && ft_strchr(str, '-'))
		size_str = ft_strlen(str) - 1;
	else
		size_str = ft_strlen(str);
	return (size_str);
}

static int	check_fmt(char f)
{
	if (f == 'd' || f == 'i' || f == 'u' || f == 'x' || f == 'X')
		return (1);
	else
		return (0);
}

char	*ft_add_precision(char *str, char f, t_lflags flag)
{
	char	*new_str;
	char	*width;

	if (*str == '0' && check_fmt(f) == 1 && flag.nbr == 0)
		new_str = ft_strdup("");
	else if (!ft_strncmp(str, "(null)", 6) && f == 's' && flag.nbr < 6)
		new_str = ft_strdup("");
	else if (flag.nbr < size(str, f) && flag.use == TRUE && f == 's')
	{
		new_str = malloc((flag.nbr + 1) * sizeof(char));
		if (!new_str)
			return (NULL);
		ft_strlcpy(new_str, str, flag.nbr + 1);
	}
	else if (flag.nbr > size(str, f) && flag.use == TRUE && f != 's')
	{
		width = ft_multichar('0', flag.nbr - size(str, f));
		new_str = ft_merge(width, str, f);
		free(width);
		return (new_str);
	}
	else
		return (str);
	free(str);
	return (new_str);
}
