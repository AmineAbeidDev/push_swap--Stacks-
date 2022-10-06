/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:23:04 by aabeid            #+#    #+#             */
/*   Updated: 2022/02/10 10:23:09 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	new = (char *) malloc ((lens1 + lens2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < lens1)
		new[i++] = s1[j++];
	j = 0;
	while (j < lens2)
		new[i++] = s2[j++];
	new[i] = '\0';
	free (s1);
	return (new);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*a;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	a = (char *)s;
	i = 0;
	j = 0;
	while (i < len && a[start + i])
		i++;
	sub = malloc((i + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (j < i)
	{
		sub[j] = a[start + j];
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
