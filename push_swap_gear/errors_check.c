/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:48:24 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/10 09:58:44 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	error_case(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	ints_checker(char *val)
{
	int	i;

	i = 0;
	while (val[i])
	{
		if (i == 0 && (val[0] == '+' || val[0] == '-'))
			i++;
		if (val[i] < '0' || val[i] > '9')
			error_case();
		i++;
	}
}

void	duplicated_checker(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if ((tab[i] == tab[j] && i != j))
				error_case();
			j++;
		}
		i++;
	}
}
