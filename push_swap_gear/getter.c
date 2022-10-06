/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:42:08 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/08 19:02:32 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

int	get_big(t_list *stack)
{
	int	val;

	val = stack->index;
	while (stack != NULL)
	{
		if (stack->index > val)
			val = stack->index;
		stack = stack->next;
	}
	return (val);
}

int	get_small(t_list *stack)
{
	int	val;

	val = stack->index;
	while (stack != NULL)
	{
		if (stack->index < val)
			val = stack->index;
		stack = stack->next;
	}
	return (val);
}
