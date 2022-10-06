/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:05:41 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/11 15:52:16 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

/*void	*del(void *cont)
{
	free(cont);
	return cont;
}

void *f(void* cont){
	int i = 0;
	char *tmp = cont;
	while (tmp[i] != 0)
	{
		if (tmp[i] == 't')
			tmp[i] = 'Z';
		i++;
	}
		return tmp;
}*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	tail = *lst;
	while (tail != 0)
	{
		if (tail -> next == 0)
		{
			tail -> next = new;
			return ;
		}
		tail = tail -> next;
	}
	if (lst == 0)
		*lst = ft_lstnew(0);
	*lst = new;
}

/*int main(){

	t_list	*n0, *n1, *n2, *n3, *n4, *tmpHead, *new;

	char *s1 = ft_strdup("Test1");
	char *s2 = ft_strdup("Test2");
	char *s3 = ft_strdup("Test3");
	char *s4 = ft_strdup("Last test");
	char *s0 = ft_strdup("newHead");

	n0 = ft_lstnew(s0);
	n1 = ft_lstnew(s1);
	n2 = ft_lstnew(s2);
	n3 = ft_lstnew(s3);
	n4 = ft_lstnew(s4);

	n1 -> next = n2;
	n2 -> next = n3;
	n3 -> next = NULL;

	ft_lstadd_front(&n1, n0);
	ft_lstadd_back(&n1, n4);
	tmpHead = n1;
	while (tmpHead != 0)
	{
		printf("%s\n", tmpHead->content);
		tmpHead = tmpHead -> next;
	}
	new = ft_lstmap(n1, &f, &del);
	while (new != 0)
	{
		printf("%s\n", new -> content);
		new = new -> next;
	}
	return 0;
}*/