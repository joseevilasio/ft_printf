/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:07:42 by tde-sous          #+#    #+#             */
/*   Updated: 2024/05/04 20:23:59 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../src/ft_printf.h"

int	main(void)
{
	char c = 'k'; // %c
	char *str = "String test"; // %s
	char *var; var = &c;// %p
	int	nbr = -5;// %d // %i
	unsigned int nbrr = 20;// %u
	int b= 0xffffffff;// %x // %X
	// %%

	int i;
	printf("Printf replica:\n");
	i = ft_printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\n| Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\n| Unsign deci: %u |\n| HexLower: %x |\n| HexUpper: %X |\n| Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b, b);
	printf("\nReturn Value: %d", i);
	///////////////////////////////
	printf("\nPrintf original:\n");
	i = printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\n| Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\n| Unsign deci: %u |\n| HexLower: %x |\n| HexUpper: %X |\n| Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b, b);
	printf("\nReturn Value: %d", i);
	return (0);
}