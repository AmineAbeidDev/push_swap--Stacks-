/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:37:55 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 13:51:51 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	twonums(t_list **s)
{
	if ((*s)->index > (*s)-> next-> index)
		swap_s(s, 1);
}

void	threenums(t_list **s, int param)
{
	if (((*s)->next->next->index > (*s)->index)
		&& ((*s)->index > (*s)->next->index))
		swap_s(s, param);
	else if (((*s)->index > (*s)->next->index)
		&& ((*s)->next->index > (*s)->next->next->index))
	{
		swap_s(s, param);
		rotate_r_s(s, param);
	}
	else if (((*s)->index > (*s)->next->next->index)
		&& ((*s)->next->next->index > (*s)->next->index))
		rotate_s(s, param);
	else if (((*s)->next->index > (*s)->next->next->index)
		&& ((*s)->next->next->index > (*s)->index))
	{
		swap_s(s, param);
		rotate_s(s, param);
	}
	else if (((*s)->next->index > (*s)->index)
		&& ((*s)->index > (*s)->next->next->index))
		rotate_r_s(s, param);
}

void	fournums(t_list **s1, t_list **s2)
{
	if (min_val_finder(*s1) <= ft_lstsize(*s1) / 2)
	{
		while ((*s1)->index != get_small(*s1))
			rotate_s(s1, 1);
	}
	else if (min_val_finder(*s1) > ft_lstsize(*s1) / 2)
	{
		while ((*s1)->index != get_small(*s1))
			rotate_r_s(s1, 1);
	}
	push_s(s1, s2, 2);
	threenums(s1, 1);
	push_s(s2, s1, 1);
}

void	fivenums(t_list **s1, t_list **s2)
{
	while (ft_lstsize(*s1) != 3)
	{
		if (min_val_finder(*s1) <= ft_lstsize(*s1) / 2)
		{
			while ((*s1)->index != get_small(*s1))
				rotate_s(s1, 1);
		}
		else if (min_val_finder(*s1) > ft_lstsize(*s1) / 2)
		{
			while ((*s1)->index != get_small(*s1))
				rotate_r_s(s1, 1);
		}
		push_s(s1, s2, 2);
	}
	threenums(s1, 1);
	push_s(s2, s1, 1);
	push_s(s2, s1, 1);
}
