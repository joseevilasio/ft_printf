/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:43:18 by josejunior        #+#    #+#             */
/*   Updated: 2024/03/30 19:25:03 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isflag(char flag, t_listflag *lflags)
{
	int	i;

	i = 0;
	while (lflags[i].flag)
	{
		if (lflags[i].flag == flag && lflags[i].exe == TRUE)
			return (1);
		i++;
	}
	return (0);
}
