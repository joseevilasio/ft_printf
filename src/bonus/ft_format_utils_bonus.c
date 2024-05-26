/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:59:10 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/26 11:05:30 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_flaglen(char *str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
			|| str[i] == '%')
			break ;
		else if (str[i] == '#' || str[i] == '+' || str[i] == ' '
			|| str[i] == '.' || str[i] == '0' || str[i] == '-')
			a++;
		else if (ft_isdigit(str[i]) == 1)
		{
			if (str[i - 1] != '0' && str[i - 1] != '.' && str[i - 1] != '-')
				a++;
			while (ft_isdigit(str[i]) == 1)
				i++;
			i--;
		}
		i++;
	}
	return (a);
}

void	lflag_clear(t_lflags *lstflags)
{
	if (lstflags)
	{
		free(lstflags);
		lstflags = NULL;
	}
}

t_lflags	ft_flagchr(t_lflags *lstflags, char flag, int mode)
{
	int	i;

	i = 0;
	if (mode == 1)
	{
		while (lstflags[i].flag)
		{
			if (lstflags[i].flag == flag)
				return (lstflags[i]);
			i++;
		}
	}
	else if (mode == 2)
	{
		while (lstflags[i].type)
		{
			if (lstflags[i].type == flag)
				return (lstflags[i]);
			i++;
		}
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
		while (i < nbr)
		{
			str[i] = c;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char	ft_getfmt(char *str)
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
	return (str[i]);
}
