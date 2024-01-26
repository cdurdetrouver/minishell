/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:49:46 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/26 18:36:57 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_quotes(char const *s, int *i)
{
	char	c;

	if (s[*i] == 34 || s[*i] == 39)
	{
		c = s[(*i)++];
		while (s[*i] && s[*i] != c)
			(*i)++;
		return (1);
	}
	return (0);
}

int	closed_quotes(char *s)
{
	int		i;
	int		closed;
	char	c;

	closed = 1;
	i = -1;
	while (s[++i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			c = s[i];
			closed = 0;
			i++;
			while (s[i] && s[i] != c)
				i++;
			if (s[i] == c)
				closed = 1;
			else if (!s[i])
				return (closed);
		}
	}
	return (closed);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
