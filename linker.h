/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:36:34 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/11 15:55:45 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKER_H
# define LINKER_H

# include <unistd.h>
# include "Get_Next_Line/get_next_line.h"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

void		rotate_r_s(t_list **stack, int param);
void		rotate_s(t_list **stack, int param);
void		push_s(t_list **from, t_list **to, int param);
void		swap_s(t_list **stack, int param);
t_list		*list_maker(t_list *head, char **elemnt, int ac);
void		twonums(t_list **s);
void		threenums(t_list **s, int param);
void		fournums(t_list **s1, t_list **s2);
void		fivenums(t_list **stack1, t_list **stack2);
int			get_small(t_list *stack);
int			get_big(t_list *stack);
void		sorter(t_list **s1, t_list **s2, int start);
void		error_case(void);
void		ints_checker(char *val);
void		duplicated_checker(int *tab, int len);
t_list		*indexing(t_list **list);
void		check_already_sorted(t_list *stack);
int			max_val_finder(t_list *s1);
int			min_val_finder(t_list *s1);
void		swap_both(t_list **s1, t_list **s2, int param);
void		rotate_both(t_list **s1, t_list **s2, int param);
void		rotate_r_both(t_list **s1, t_list **s2, int param);
long long	ft_atoi(const char *str);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);

typedef struct t_vals
{
	int	range;
	int	max;
	int	mid;
}	t_vals_container;

#endif