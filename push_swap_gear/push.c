/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:18:41 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/11 15:59:43 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	push_s(t_list **from, t_list **to, int param)
{
	t_list	*front;

	if (ft_lstsize(*from) < 1)
		return ;
	front = *from;
	*from = (*from)->next;
	front->next = NULL;
	ft_lstadd_front(to, front);
	if (param == 1)
		write(1, "pa\n", 3);
	else if (param == 2)
		write(1, "pb\n", 3);
}
