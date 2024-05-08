/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserflags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:47 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/07 23:38:46 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	add_flag(char f, t_lflags *lstflags, t_bool use, char type, int nbr)
{
	if (lstflags)
	{
		lstflags->flag = f;
		lstflags->type = type;
		lstflags->use = use;
		lstflags->number = ft_atoi(nbr);
	}
}

static int	add_number(char *str, t_lflags *lstflags, char flag)
{
	char	*nbr;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (ft_isdigit(str[i]) == 1)
		i++;
	nbr = (char *) malloc((i + 1) * sizeof(char));
	if (str != NULL && nbr)
	{
		while (ft_isdigit(str[i]) == 1)
		{
			nbr[i] = str[i];
			i++;
		}
		nbr[i] = '\0';
	}
	if ()// verificar flag '- 0 vazio .' se encontrar adicionar numero no lugar correto
	//free(nbr);
}

static void	get_flag(char *str, t_lflags *lstflags, int limit)
{
	int		i;

	i = 0;
	while (limit > i)
	{
		if (*str == '#')
			add_flag('#', &lstflags[i], FALSE, 'a', 0); //a = adicionar
		else if (*str == '.')
			add_flag('.', &lstflags[i], FALSE, 'p', 0); //p = presicion 
		else if (*str == '+')
			add_flag('+', &lstflags[i], FALSE, 'a', 0);
		else if (*str == ' ')
			add_flag(' ', &lstflags[i], FALSE, 'a', 0);
		else if (*str == '0')
			add_flag('0', &lstflags[i], FALSE, 'a', 0);
		else if (*str == '-')
			add_flag('-', &lstflags[i], FALSE, 'w', 0); // w justificar a direita
		else if (ft_isdigit(*str) == 1)	
			str = str + add_number(str, &lstflags[i], *(str - 1));
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
		else if (lstflags[a].flag == '.' && f != 'p' && f != 'c') //validar
			lstflags[a].use = TRUE;
		else if ((lstflags[a].flag == '+' || lstflags[a].flag == ' ')
			&& (f == 'd' || f == 'i') && ft_strchr(str, '-') == NULL)
			lstflags[a].use = TRUE;
		else if (lstflags[a].flag == '0' && (f != 'c' && f != 's' && f != 'p' && f != '%'))
		{
			lstflags[a].use = TRUE;
			if (ft_flagchr('-', lstflags) == TRUE)
				lstflags[a].use = FALSE;
		}
		// else if (lstflags[a].flag == '-' && n > 0) //verificar se a flag recebeu number
		// 	lstflags[a].use = TRUE;
		// else if (lstflags[a].flag == 'n' && ft_isflag('-', lstflags) == 1) //talvez excluir
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
