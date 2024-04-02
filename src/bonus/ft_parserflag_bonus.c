/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserflag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:14:22 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/01 23:20:21 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	add_flag(char flag, t_listflag *lflags, t_bool cond)
{
	if (lflags)
	{
		lflags->flag = flag;
		lflags->exe = cond;
	}
}

static void	add_flag_n(char *str, char **n, t_listflag *lflags)
{
	char	*str_n;
	int		i;

	i = 0;
	str_n = (char *) malloc(10 * sizeof(char) + 1);
	if (str != NULL)
	{
		while (ft_isdigit(str[i]) == 1)
		{
			str_n[i] = str[i];
			i++;
		}
		str_n[i] = '\0';
		*n = str_n;
		add_flag('n', lflags, TRUE);
	}
}

static void	get_flag(char *str, t_listflag *lflags, int limit, char **n)
{
	int		i;

	i = 0;
	while (limit > i)
	{
		if (*str == '#')
			add_flag('#', &lflags[i], FALSE);
		else if (*str == '.')
			add_flag('.', &lflags[i], FALSE);
		else if (*str == '+')
			add_flag('+', &lflags[i], FALSE);
		else if (*str == ' ')
			add_flag(' ', &lflags[i], FALSE);
		else if (*str == '0')
			add_flag('0', &lflags[i], FALSE);
		else if (*str == '-')
			add_flag('-', &lflags[i], FALSE);
		else if (ft_isdigit(*str) == 1 || *str != 0)
		{
			add_flag_n(str, n, &lflags[i]);
			i += ft_strlen(*n);
		}
		i++;
		str++;
	}
}

static void	mode_flag(t_listflag *lflags, va_list args, char f, int n)
{
	int	a;

	a = 0;
	while (lflags[a].flag)
	{
		if (lflags[a].flag == '#' && (f == 'x' || f == 'X'))
			lflags[a].exe = TRUE;
		else if (lflags[a].flag == '.' && f != 'p' && f != 'c')
			lflags[a].exe = TRUE;
		else if ((lflags[a].flag == '+' || lflags[a].flag == ' ')
			&& (f == 'd' || f == 'i') && va_arg(args, int) >= 0)
			lflags[a].exe = TRUE;
		else if (lflags[a].flag == '0' && (f != 'c' && f != 's' && f != 'p')
			&& n > 0)
		{
			lflags[a].exe = TRUE;
			if (ft_isflag('-', lflags) == 1)
				lflags[a].exe = FALSE;
		}
		else if (lflags[a].flag == '-' && n > 0)
			lflags[a].exe = TRUE;
		else if (lflags[a].flag == 'n' && ft_isflag('-', lflags) == 1)
			lflags[a].exe = FALSE;
		a++;
	}
}

int	ft_parserflag(char *str, va_list args, t_listflag **lflags, char **n)
{
	int			i;
	int			len_flag;
	va_list		copy_args;

	i = 0;
	len_flag = ft_length_flags(str);
	*lflags = ft_calloc(len_flag + 1, sizeof(t_listflag));
	va_copy(copy_args, args);
	if (lflags)
	{
		get_flag(str, *lflags, len_flag, n);
		if (*n == 0)
		{
			*n = ft_calloc(2, sizeof(char));
			ft_strlcpy(*n, "0", 2);
		}
		str += len_flag;
		if (lflags[0]->flag)
			mode_flag(*lflags, copy_args, *str, ft_atoi(*n));
	}
	return (i);
}
