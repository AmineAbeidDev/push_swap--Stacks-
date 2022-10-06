/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:45:30 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/11 16:00:02 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	swap_s(t_list **s, int param)
{
	int	swp;
	int	swp2;

	if (ft_lstsize(*s) < 2)
		return ;
	swp = (*s)->content;
	swp2 = (*s)->index;
	(*s)->content = (*s)->next->content;
	(*s)->index = (*s)->next->index;
	(*s)->next->content = swp;
	(*s)->next->index = swp2;
	if (param == 1)
		write(1, "sa\n", 3);
	else if (param == 2)
		write(1, "sb\n", 3);
}

void	swap_both(t_list **s1, t_list **s2, int param)
{
	swap_s(s1, 3);
	swap_s(s2, 3);
	if (param == 3)
		write(1, "ss\n", 3);
}
