/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:14:28 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/13 09:49:30 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linker.h"
#include <fcntl.h>

int	check_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		i++;
	}
	return (1);
}

void	ops_reader(char *op, t_list **s1, t_list **s2)
{
	if (ft_strcmp(op, "pa\n", 3))
		push_s(s2, s1, 4);
	else if (ft_strcmp(op, "pb\n", 3))
		push_s(s1, s2, 4);
	else if (ft_strcmp(op, "sa\n", 3))
		swap_s(s1, 4);
	else if (ft_strcmp(op, "sb\n", 3))
		swap_s(s2, 4);
	else if (ft_strcmp(op, "ss\n", 3))
		swap_both(s1, s2, 4);
	else if (ft_strcmp(op, "ra\n", 3))
		rotate_s(s1, 4);
	else if (ft_strcmp(op, "rb\n", 3))
		rotate_s(s2, 4);
	else if (ft_strcmp(op, "rr\n", 3))
		rotate_both(s1, s2, 4);
	else if (ft_strcmp(op, "rra\n", 4))
		rotate_r_s(s1, 4);
	else if (ft_strcmp(op, "rrb\n", 4))
		rotate_r_s(s2, 4);
	else if (ft_strcmp(op, "rrr\n", 4))
		rotate_r_both(s1, s2, 4);
	else
		error_case();
}

int	main(int ac, char **av)
{
	char	*input;
	t_list	*stack1;
	t_list	*stack2;

	if (ac < 3)
		return (0);
	stack1 = NULL;
	stack2 = NULL;
	stack1 = list_maker(stack1, av, ac);
	stack1 = indexing(&stack1);
	input = get_next_line(0);
	while (input)
	{
		ops_reader(input, &stack1, &stack2);
		free(input);
		input = get_next_line(0);
	}
	if (check_sorted(stack1) == 1 && !stack2)
		write(1, "OK\n", 3);
	else if (check_sorted(stack1) == 0 || (check_sorted(stack1) == 1 && stack2))
		write(1, "KO\n", 3);
	return (0);
}
