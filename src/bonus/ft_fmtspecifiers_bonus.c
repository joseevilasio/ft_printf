/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtspecifiers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:18:24 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/07 23:37:32 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*merge(char *s1, char *s2)
{
	char *new;
	
	new = ft_strjoin(s1, s2);
	free(s2);
	return (new);
}

static char *add(char *str, char fmt, t_lflags *lstflags)
{
	char	*new_str;
	int		a;

	a = 0;
	new_str = (char *) malloc(sizeof(char));
	*new_str = 0;
	if (lstflags[a].flag == '#' && lstflags[a].use == TRUE)
	{
		if (fmt == 'x')
			new_str = merge("0x", str);
		else
			new_str = merge("0X", str);
	}
	else if (lstflags[a].flag == '+' && lstflags[a].use == TRUE)
		new_str = merge("+", str);
	else if (lstflags[a].flag == ' ' && lstflags[a].use == TRUE)
		new_str = merge(" ", str);
	else
		free(str);
	return (new_str);
}

char	*ft_fmtspecifiers(char *str, t_lflags *lstflags, char f)
{
	int		a;
	char	*new_str;

	a = 0;
	new_str = (char *) malloc(sizeof(char));
	*new_str = 0;
	while (lstflags[a].flag)
	{
		if (lstflags[a].type == 'a') //verificar prioriades
			new_str = add(str, f, lstflags);
		// else if (lstflags[a].type == 'a')
		// 	new_str = add(str, f, lstflags); //precisao
		// else if (lstflags[a].type == 'a')
		// 	new_str = add(str, f, lstflags); //left
		a++;
	}
	if (!*new_str)
	{
		free(new_str);
		return (str);
	}
	return (new_str);
}
