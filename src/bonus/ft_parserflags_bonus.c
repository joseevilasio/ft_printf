/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserflags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:47 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/26 17:43:29 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	add_flag(char f, t_lflags *lflags, char type, char *nbr)
{
	if (lflags)
	{
		lflags->flag = f;
		lflags->type = type;
		lflags->use = FALSE;
		lflags->nbr = ft_atoi(nbr);
	}
}

static int	add_number(char *str, t_lflags *lflags, char flag, int indice)
{
	char	*nbr;
	int		i;

	i = 0;
	while (ft_isdigit(str[i]) == 1)
		i++;
	nbr = (char *) malloc((i + 1) * sizeof(char));
	i = 0;
	if (str != NULL && nbr)
	{
		while (ft_isdigit(str[i]) == 1)
		{
			nbr[i] = str[i];
			i++;
		}
		nbr[i] = '\0';
	}
	if ((flag == '-' || flag == '0') && !ft_flagchr(lflags, '.', 1).flag)
		add_flag(flag, &lflags[indice - 1], 'w', nbr);
	else if (flag == '.' || ft_flagchr(lflags, '.', 1).flag)
		add_flag(flag, &lflags[indice - 1], 'p', nbr);
	else
		add_flag('n', &lflags[indice], 'w', nbr);
	free(nbr);
	return (i - 1);
}

static void	get_flag(char *str, t_lflags *lflags, char fmt)
{
	int	i;

	i = 0;
	while (*str != fmt)
	{
		if (*str == '#')
			add_flag('#', &lflags[i++], 'a', "0");
		else if (*str == '+')
			add_flag('+', &lflags[i++], 'a', "0");
		else if (*str == ' ')
			add_flag(' ', &lflags[i++], 'a', "0");
		else if (*str == '.')
			add_flag('.', &lflags[i++], 'p', "0");
		else if (*str == '0' && *(str - 1) != '.')
			add_flag('0', &lflags[i++], 'w', "0");
		else if (*str == '-')
			add_flag('-', &lflags[i++], 'w', "0");
		else if (ft_isdigit(*str) == 1)
		{
			str = str + add_number(str, lflags, *(str - 1), i);
			if (lflags[i].flag == 'n')
				i++;
		}
		str++;
	}
}

static void	mode_flag(t_lflags *lflags, char *str, char f)
{
	int	a;

	a = 0;
	while (lflags[a].flag)
	{
		if (lflags[a].flag == '#' && (f == 'x' || f == 'X') && *str != '0')
			lflags[a].use = TRUE;
		else if ((lflags[a].flag == '+' || lflags[a].flag == ' ')
			&& (f == 'd' || f == 'i') && ft_strchr(str, '-') == NULL)
			lflags[a].use = TRUE;
		else if (lflags[a].flag == '0' || lflags[a].flag == '.'
			|| lflags[a].flag == 'n' || lflags[a].flag == '-')
			lflags[a].use = TRUE;
		a++;
	}
}

char	*ft_parserflags(char *flags, va_list args)
{
	t_lflags	*lflags;
	char		*specifier;
	char		fmt;
	int			size;

	size = ft_flaglen(flags);
	fmt = ft_getfmt(flags);
	lflags = NULL;
	if (size > 0)
		lflags = ft_calloc((size + 1), sizeof(t_lflags));
	if (lflags)
	{
		get_flag(flags, lflags, fmt);
		specifier = ft_format(args, fmt);
		mode_flag(lflags, specifier, fmt);
		specifier = ft_fmtspecifiers(specifier, lflags, fmt);
		lflag_clear(lflags);
		return (specifier);
	}
	else
	{
		specifier = ft_format(args, fmt);
		return (specifier);
	}
	return (NULL);
}
