/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:17:36 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/09 14:13:33 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

t_list	*sorting_by_index(t_list *head, int *index)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head -> content == index[i])
		{
			head -> index = i;
			i = 0;
			head = head -> next;
		}
		else
			i++;
	}
	return (head);
}

int	*arr_sorter(int *arr, int len)
{
	int	i;
	int	swp;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i + 1] < arr[i])
		{
			swp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = swp;
			i = -1;
		}
		i++;
	}
	duplicated_checker(arr, len);
	return (arr);
}

t_list	*indexing(t_list **list)
{
	int		*index;
	int		i;
	t_list	*head;

	head = *list;
	i = 0;
	index = malloc(sizeof(int) * ft_lstsize(head));
	while (head)
	{
		index[i] = head -> content;
		head = head -> next;
		i++;
	}
	index = arr_sorter(index, i);
	head = *list;
	head = sorting_by_index(head, index);
	free(index);
	head = *list;
	return (head);
}

t_list	*list_maker(t_list *head, char **element, int ac)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		ints_checker(element[i]);
		ft_lstadd_back(&head, ft_lstnew(ft_atoi(element[i++])));
		if (ft_atoi(element[i - 1]) > 2147483647
			|| ft_atoi(element[i - 1]) < -2147483648)
			error_case();
	}
	return (head);
}
