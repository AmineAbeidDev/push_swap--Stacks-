/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:55:06 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/11 15:59:53 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	rotate_r_s(t_list **s, int param)
{
	t_list	*tmp;
	t_list	*head;

	if (ft_lstsize(*s) < 2)
		return ;
	tmp = ft_lstlast(*s);
	head = *s;
	while ((*s)->next->next != NULL)
		(*s) = (*s)->next;
	(*s)->next = NULL;
	tmp->next = head;
	*s = tmp;
	if (param == 1)
		write(1, "rra\n", 4);
	else if (param == 2)
		write(1, "rrb\n", 4);
}

void	rotate_r_both(t_list **s1, t_list **s2, int param)
{
	rotate_r_s(s1, 3);
	rotate_r_s(s2, 3);
	if (param == 3)
		write(1, "rrr\n", 4);
}
