/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtspecifiers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:18:24 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/15 22:57:55 by joneves-         ###   ########.fr       */
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

// static char	*add_width(char *str, char fmt, t_lflags lstflags)
// {
// 	char	*new_str;

// 	if (lstflags.flag == '0' && lstflags.use == TRUE)
// 	{
// 		new_str = merge("0x", str);
// 		else
// 			new_str = merge("0X", str);
// 	}
// 	else if (lstflags.flag == '+' && lstflags.use == TRUE)
// 		new_str = merge("+", str);
// 	else if (lstflags.flag == ' ' && lstflags.use == TRUE)
// 		new_str = merge(" ", str);
// 	else
// 		return (str);
// 	return (new_str);
// }

// static char	*add_precision(char *str, char fmt, t_lflags lstflags)
// {
// 	char	*new_str;

// 	if (lstflags.flag == '0' && lstflags.use == TRUE)
// 	{
// 		new_str = merge("0x", str);
// 		else
// 			new_str = merge("0X", str);
// 	}
// 	else if (lstflags.flag == '+' && lstflags.use == TRUE)
// 		new_str = merge("+", str);
// 	else if (lstflags.flag == ' ' && lstflags.use == TRUE)
// 		new_str = merge(" ", str);
// 	else
// 		return (str);
// 	return (new_str);
// }

char	*ft_fmtspecifiers(char *str, t_lflags *lstflags, char f)
{
	int		a;
	char	*specifier;

	a = 0;
	specifier = str;
	while (lstflags[a].flag)
	{
		if (lstflags[a].type == 'a') //verificar prioriades
			specifier = add_prefix(specifier, f, lstflags[a]);
		// else if (lstflags[a].type == 'p')
		// 	ptr_str = add(str, f, lstflags); //precisao
		// else if (lstflags[a].type == 'w')
		// 	specifier = add_width(specifier, f, lstflags[a]); //fazer nova funcao para adicionar alinhamento tanto para direita como para esquerda, com ou sem zeros.
		a++;
	}
	// if (!ptr_str)
	// {
	// 	free(ptr_str);
	// 	return (str); //verificar se retorna NULL
	// }
	return (specifier);
}
