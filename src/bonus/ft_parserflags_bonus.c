/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserflags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:47 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/21 22:19:24 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	add_flag(char f, t_lflags *lflags, t_bool use, char type, char *nbr)
{
	if (lflags)
	{
		lflags->flag = f;
		lflags->type = type;
		lflags->use = use;
		lflags->number = ft_atoi(nbr);
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
	if (flag == '-' || flag == '0')
		add_flag(flag, &lflags[indice - 1], TRUE, 'w', nbr);
	else if (flag == '.')
		add_flag(flag, &lflags[indice - 1], TRUE, 'p', nbr);
	else //add space
		add_flag('n', &lflags[indice], TRUE, 'w', nbr);
	free(nbr);
	return (i);
}

static void	get_flag(char *str, t_lflags *lflags, int limit)
{
	int		i;

	i = 0;
	while (limit > i)
	{
		if (*str == '#')
			add_flag('#', &lflags[i], FALSE, 'a', "0");
		else if (*str == '+')
			add_flag('+', &lflags[i], FALSE, 'a', "0");
		else if (*str == ' ')
			add_flag(' ', &lflags[i], FALSE, 'a', "0");
		else if (*str == '.')
			add_flag('.', &lflags[i], FALSE, 'p', "0");
		else if (*str == '0')
			add_flag('0', &lflags[i], FALSE, 'w', "0");
		else if (*str == '-')
			add_flag('-', &lflags[i], FALSE, 'w', "0");
		else if (ft_isdigit(*str) == 1)	
			str = str + add_number(str, lflags, *(str - 1), i);
		i++;
		str++;
	}
	add_flag('\0', &lflags[i], FALSE, '\0', "0");
}

static void	mode_flag(t_lflags *lflags, char *str, char f)
{
	int	a;

	a = 0;
	while (lflags[a].flag)
	{
		if (lflags[a].flag == '#' && (f == 'x' || f == 'X'))
			lflags[a].use = TRUE;
		else if (lflags[a].flag == '.' && (f == 's' || f == 'x' || f == 'X'))
			lflags[a].use = TRUE;
		else if ((lflags[a].flag == '+' || lflags[a].flag == ' ')
			&& (f == 'd' || f == 'i') && ft_strchr(str, '-') == NULL)
			lflags[a].use = TRUE;
		else if (lflags[a].flag == '0' && (f != 'c' && f != 's' && f != 'p' 
			&& f != '%'))
		{
			lflags[a].use = TRUE;
			// if (!ft_flagchr(lflags, '-').flag)
			// 	lflags[a].use = FALSE;
		}
		// else if (lflags[a].flag == '-' && n > 0) //verificar se a flag recebeu number
		// 	lflags[a].use = TRUE;
		// else if (lflags[a].flag == 'n' && ft_isflag('-', lflags) == 1) //talvez excluir
		// 	lflags[a].use = FALSE;
		a++;
	}
}

char	*ft_parserflags(char *flags, va_list args)
{
	char		*specifier;
	t_lflags	*lflags;
	int			size;

	size = ft_flaglen(flags);
	lflags = NULL;
	if (size > 0)
		lflags = ft_calloc((size + 1), sizeof(t_lflags));
	if (lflags)
	{
		get_flag(flags, lflags, size);
		specifier = ft_format(args, flags[size]);
		mode_flag(lflags, specifier, flags[size]);
		specifier = ft_fmtspecifiers(specifier, lflags, flags[size]);
		lflag_clear(lflags);
		return (specifier);
	}
	else
	{
		specifier = ft_format(args, flags[size]);
		return (specifier);
	}
	return (NULL);
}

// Para verificar
// -> efeito do calloc
// -> verificar se ft de tamanho esta correto
// -> corrigir quando recebe um %c NULL
// -> corrigir quando %d e %i e negativo com 0 e -