/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:57 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/26 20:07:59 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
