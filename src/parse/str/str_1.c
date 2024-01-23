/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:37:41 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/23 00:57:28 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_quotes(char *str)
{
	char	*ret;
	int		i;
	int		j;
	char	c;

	ret = malloc(ft_strlen(str) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i++];
			while (str[i] && str[i] != c)
				ret[j++] = str[i++];
		}
		else
			ret[j++] = str[i];
	}
	ret[j] = 0;
	return (ret);
}

int	skip_and_copy(char *str, char *ret, int *i, int *j)
{
	char	c;

	if (str[*i] && (str[*i] == 34 || str[*i] == 39))
	{
		c = str[(*i)];
		ret[(*j)++] = str[(*i)++];
		while (str[*i] && str[*i] != c)
			ret[(*j)++] = str[(*i)++];
		if (str[*i])
			ret[(*j)++] = str[(*i)++];
		return (1);
	}
	return (0);
}

void	skip_spaces(char *str, int *i, int *j)
{
	if (str[*i] && is_space(str[*i]))
	{
		while (str[*i] && is_space(str[*i]))
		{
			i++;
			j++;
		}
	}
}

char	*remove_spaces(char *s)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (is_space(s[i]))
		{
			ret[j++] = 31;
			i++;
		}
		else
		{
			if (!skip_and_copy(s, ret, &i, &j) && s[i] && !is_space(s[i]))
				ret[j++] = s[i++];
		}
	}
	ret[j] = 0;
	return (ret);
}

int	spaces_to_add(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '|' || s[i] == '>' || s[i] == '<' || s[i] == '\\'
			|| s[i] == '&' || s[i] == ';')
		{
			count += 2;
			i++;
		}
		else
		{
			if (!skip_quotes(s, &i))
				i++;
		}
	}
	return (count);
}
