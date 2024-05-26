/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:59:10 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/26 17:09:34 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_checklen(char *str, char fmt)
{
	if (fmt == 'c' && !str)
		return (1);
	else
		return (ft_strlen(str));
}

char	*ft_merge(char *s1, char *s2, int fmt)
{
	char	*new;
	char	*swap;

	if (fmt == 'd' || fmt == 'i')
	{
		if (ft_strchr(s2, '-') && !ft_strchr(s1, ' '))
		{
			swap = ft_strjoin(s1, (s2 + 1));
			new = ft_strjoin("-", swap);
			free(swap);
		}
		else
			new = ft_strjoin(s1, s2);
	}
	else if (fmt == 'c' && !s2)
		new = ft_strdup(s1);
	else if (fmt == 'c' && !s1)
		new = ft_strdup(s2);
	else
		new = ft_strjoin(s1, s2);
	free(s2);
	return (new);
}
