/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:02:30 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/11 15:52:24 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

t_list	*ft_lstnew(int content)
{
	t_list	*p;

	p = malloc(sizeof (t_list));
	if (p == NULL)
		return (NULL);
	p -> content = content;
	p -> next = NULL;
	return (p);
}
