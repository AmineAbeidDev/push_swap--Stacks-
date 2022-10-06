/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:41:03 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/10 10:15:22 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

int	min_val_finder(t_list *s1)
{
	int		saved_idx;
	int		saved_val;
	int		idx;

	idx = 0;
	if (!s1)
		return (0);
	saved_val = s1->index;
	saved_idx = idx;
	while (s1)
	{
		if (s1->index < saved_val)
		{
			saved_val = s1->index;
			saved_idx = idx;
		}
		s1 = s1->next;
		idx++;
	}
	return (saved_idx);
}

int	max_val_finder(t_list *s1)
{
	int		saved_idx;
	int		saved_val;
	int		idx;

	idx = 0;
	if (!s1)
		return (0);
	saved_val = s1->index;
	saved_idx = idx;
	while (s1)
	{
		if (s1->index > saved_val)
		{
			saved_val = s1->index;
			saved_idx = idx;
		}
		s1 = s1->next;
		idx++;
	}
	return (saved_idx);
}

void	sorter3(t_list **s1, t_list **s2)
{
	while (*s2)
	{
		if (((*s1)->index - 1) == (*s2)->index)
			push_s(s2, s1, 1);
		else if (((*s2)->index < (*s1)->index)
			&& (*s2)->index > ft_lstlast(*s1)->index)
		{
			push_s(s2, s1, 1);
			rotate_s(s1, 1);
		}
		else if ((ft_lstlast(*s1)->index) == (*s1)->index - 1)
			rotate_r_s(s1, 1);
		else if (max_val_finder(*s2) > (ft_lstsize(*s2) / 2))
			rotate_r_s(s2, 2);
		else if (max_val_finder(*s2) <= (ft_lstsize(*s2) / 2))
			rotate_s(s2, 2);
		else if ((ft_lstlast(*s1)->index) - 1 == (*s1)->index)
			rotate_r_s(s1, 1);
	}
	while ((ft_lstlast(*s1)->index) < (*s1)->index
		&& (ft_lstlast(*s1)->index) != -1)
		rotate_r_s(s1, 1);
}

void	sorter2(t_list **s1, t_list **s2, t_vals_container val, int start)
{
	while (ft_lstsize(*s1) != 5)
	{
		while (ft_lstsize(*s2) != val.range + start)
		{
			if (((*s1)->index >= start) && ((*s1)->index <= val.max))
			{
				if ((*s1)->index < val.mid)
				{
					push_s(s1, s2, 2);
					rotate_s(s2, 2);
				}
				else
					push_s(s1, s2, 2);
			}
			else if (min_val_finder(*s1) <= (ft_lstsize(*s1) / 2))
				rotate_s(s1, 1);
			else if (min_val_finder(*s1) > (ft_lstsize(*s1) / 2))
				rotate_r_s(s1, 1);
		}
		start = ft_lstsize(*s2);
		val.range = ((ft_lstsize(*s1) - 5) / 3) + 1;
		val.max = val.range + start - 1;
		val.mid = (start + val.max) / 2;
	}
}

void	sorter(t_list **s1, t_list **s2, int min)
{
	t_vals_container	val;

	val.range = ((ft_lstsize(*s1) - 5) / 3) + 1;
	val.max = val.range + min - 1;
	val.mid = (min + val.max) / 2;
	sorter2(s1, s2, val, min);
	fivenums(s1, s2);
	ft_lstlast(*s1)->index = -1;
	sorter3(s1, s2);
}
