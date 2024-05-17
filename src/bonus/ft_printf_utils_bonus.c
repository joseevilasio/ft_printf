/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:59:10 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/15 23:09:43 by joneves-         ###   ########.fr       */
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

int	ft_flaglen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
			|| str[i] == '%')
			break ;
		i++;
	}
	return (i);
}

void	lflag_clear(t_lflags *lstflags)
{
	if (lstflags)
	{
		free(lstflags);
		lstflags = NULL;
	}
}

t_lflags	ft_flagchr(t_lflags *lstflags, char flag)
{
	int	i;

	i = 0;
	while (lstflags[i].flag)
	{
		if (lstflags[i].flag == flag)
			return (lstflags[i]);
		i++;
	}
	return (lstflags[i]);
}

char	*ft_multichar(char c, int nbr)
{
	char	*str;
	int		i;

	str = malloc((nbr + 1) * sizeof(char));
	if (str)
	{
		i = 0;
		while (i <= nbr)
		{
			str[i] = c;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
