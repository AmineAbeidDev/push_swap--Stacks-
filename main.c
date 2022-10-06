/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:09:11 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/13 09:48:44 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linker.h"

void	check_already_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return ;
		stack = stack->next;
	}
	exit(0);
}

int	main(int ac, char **av)
{
	t_list	*stack1;
	t_list	*stack2;

	if (ac < 2)
		return (0);
	stack1 = NULL;
	stack1 = list_maker(stack1, av, ac);
	stack1 = indexing(&stack1);
	check_already_sorted(stack1);
	if (ft_lstsize(stack1) == 2)
		twonums(&stack1);
	else if (ft_lstsize(stack1) == 3)
		threenums(&stack1, 1);
	else if (ft_lstsize(stack1) == 4)
		fournums(&stack1, &stack2);
	else if (ft_lstsize(stack1) == 5)
		fivenums(&stack1, &stack2);
	else
		sorter(&stack1, &stack2, 0);
	return (0);
}
