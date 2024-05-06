/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserflags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:47 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/06 13:42:44 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	add_flag(char flag, t_lflags *lstflags, t_bool use, char type)
{
	if (lstflags)
	{
		lstflags->flag = flag;
		lstflags->type = type;
		lstflags->use = use;
	}
}

// static void	add_flag_n(char *str, char **n, t_listflag *lstflags)
// {
// 	char	*str_n;
// 	int		i;

// 	i = 0;
// 	str_n = (char *) malloc(10 * sizeof(char) + 1);
// 	if (str != NULL)
// 	{
// 		while (ft_isdigit(str[i]) == 1)
// 		{
// 			str_n[i] = str[i];
// 			i++;
// 		}
// 		str_n[i] = '\0';
// 		*n = str_n;
// 		add_flag('n', lstflags, TRUE);
// 	}
// }

static void	get_flag(char *str, t_lflags *lstflags, int limit)
{
	int		i;

	i = 0;
	while (limit > i)
	{
		if (*str == '#')
			add_flag('#', &lstflags[i], FALSE, 'a');
		else if (*str == '.')
			add_flag('.', &lstflags[i], FALSE, 'f');
		else if (*str == '+')
			add_flag('+', &lstflags[i], FALSE, 'a');
		else if (*str == ' ')
			add_flag(' ', &lstflags[i], FALSE, 'a');
		else if (*str == '0')
			add_flag('0', &lstflags[i], FALSE, 'f');
		else if (*str == '-')
			add_flag('-', &lstflags[i], FALSE, 'f');
		// else if (ft_isdigit(*str) == 1 || *str != 0)
		// {
		// 	add_flag_n(str, n, &lstflags[i]);
		// 	i += ft_strlen(*n);
		// }
		i++;
		str++;
	}
}

static void	mode_flag(t_lflags *lstflags, char *str, char f)
{
	int	a;

	a = 0;
	while (lstflags[a].flag)
	{
		if (lstflags[a].flag == '#' && (f == 'x' || f == 'X'))
			lstflags[a].use = TRUE;
		else if (lstflags[a].flag == '.' && f != 'p' && f != 'c')
			lstflags[a].use = TRUE;
		else if ((lstflags[a].flag == '+' || lstflags[a].flag == ' ')
			&& (f == 'd' || f == 'i') && ft_strchr(str, '-') == NULL)
			lstflags[a].use = TRUE;
		// else if (lstflags[a].flag == '0' && (f != 'c' && f != 's' && f != 'p'))
		// {
		// 	lstflags[a].use = TRUE;
		// 	if (ft_isflag('-', lstflags) == 1)
		// 		lstflags[a].use = FALSE;
		// }
		// else if (lstflags[a].flag == '-' && n > 0)
		// 	lstflags[a].use = TRUE;
		// else if (lstflags[a].flag == 'n' && ft_isflag('-', lstflags) == 1)
		// 	lstflags[a].use = FALSE;
		a++;
	}
}

char	*ft_parserflags(char *flags, va_list args)
{
	char		*specifier_;
	t_lflags	*lstflags;
	int			size;

	size = ft_flaglen(flags);
	lstflags = ft_calloc(size, sizeof(t_lflags));
	if (lstflags)
	{
		get_flag(flags, lstflags, size);
		specifier_ = ft_format(args, flags[size]);
		mode_flag(lstflags, specifier_, flags[size]);
		specifier_ = ft_fmtspecifiers(specifier_, lstflags, flags[size]);
		lflag_clear(lstflags);
		return (specifier_);
	}
	return (NULL);
}
