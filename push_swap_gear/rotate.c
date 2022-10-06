/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:51:22 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 13:51:33 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	rotate_s(t_list **stack, int param)
{
	int		tmp;
	int		tmp2;
	t_list	*top;

	if (ft_lstsize(*stack) < 2)
		return ;
	top = *stack;
	tmp = top -> content;
	tmp2 = top -> index;
	while (top -> next != NULL)
	{
		top -> content = top -> next -> content;
		top -> index = top -> next -> index;
		top = top -> next;
	}
	top -> content = tmp;
	top -> index = tmp2;
	if (param == 1)
		write(1, "ra\n", 3);
	else if (param == 2)
		write(1, "rb\n", 3);
}

void	rotate_both(t_list **s1, t_list **s2, int param)
{
	rotate_s(s1, 3);
	rotate_s(s2, 3);
	if (param == 3)
		write(1, "rr\n", 3);
}
