/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:58:31 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/11 15:52:30 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*count;

	i = 0;
	count = lst;
	while (count != 0)
	{
		i++;
		count = count -> next;
	}
	return (i);
}
