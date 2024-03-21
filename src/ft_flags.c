/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:28:47 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/21 15:41:15 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_flag(char flag, t_listflag *l_flags)
{
	if (l_flags)
	{
		l_flags->flag = flag;
		l_flags->execute = FALSE;
	}
}

static void	add_flag_n(char *str, char **n)
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
	}
}

static void	get_flag(char *str, t_listflag *l_flags, int limit, char **n)
{
	int		i;

	i = 0;
	while (limit > i)
	{
		if (*str == '#')
			add_flag('#', &l_flags[i]);
		else if (*str == '+')
			add_flag('+', &l_flags[i]);
		else if (*str == ' ')
			add_flag(' ', &l_flags[i]);
		else if (*str == '0')
			add_flag('0', &l_flags[i]);
		else if (*str == '-')
			add_flag('-', &l_flags[i]);
		else if (ft_isdigit(*str) == 1 || *str != 0)
		{
			add_flag_n(str, n);
			i += ft_strlen(*n);
		}
		i++;
		str++;
	}
}

static void	mode_flag(t_listflag *l_flags, va_list args, char f, int n)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	while (l_flags[a].flag)
	{
		if (l_flags[a].flag == '#' && (f == 'x' || f == 'X'))
			l_flags[a].execute = TRUE;
		else if ((l_flags[a].flag == '+' || l_flags[a].flag == ' ')
			&& (f == 'd' || f == 'i') && va_arg(args, int) > 0)
			l_flags[a].execute = TRUE;
		else if (l_flags[a].flag == '0' && (f == 'x' || f == 'X' || f == 'd'
			|| f == 'i') && n > 0)
		{
			l_flags[a].execute = TRUE;
			while (l_flags[i].flag && l_flags[i].flag == '-')
				l_flags[a].execute = FALSE;
		}
		else if (l_flags[a].flag == '-' && n > 0)
			l_flags[a].execute = TRUE;
		a++;
	}
}

int	ft_flags(char *str, va_list args)
{
	int			i;
	char		*n;
	t_listflag	*l_flags;
	va_list		copy_args;

	i = 0;
	l_flags = NULL;
	n = NULL;
	l_flags = ft_calloc(ft_length_flags(str) + 1, sizeof(t_listflag));
	if (l_flags)
	{
		get_flag(str, l_flags, ft_length_flags(str), &n);
		if (n == 0)
		{
			n = ft_calloc(2, sizeof(char));
			ft_strlcpy(n, "0", 1);
		}
		str += ft_length_flags(str);
		va_copy(copy_args, args);
		mode_flag(l_flags, copy_args, *str, ft_atoi(n));
		i += ft_format(args, *str, l_flags, 0);
		free(n);
	}
	free(l_flags);
	return (i);
}
