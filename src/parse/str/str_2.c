/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:04:53 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/11 22:01:19 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	space_func(char *s, char *ret, int *i, int *j)
{
	char	c;

	if (s[(*i)] && (s[(*i)] == '|' || s[(*i)] == '>' || s[(*i)] == '<'))
	{
		c = s[(*i)];
		if (*i > 0 && s[(*i) - 1] && s[(*i) - 1] != s[(*i)])
			ret[(*j)++] = 31;
		ret[(*j)++] = s[(*i)++];
		if (s[(*i)] != c)
			ret[(*j)++] = 31;
		if (s[(*i)] && s[(*i) - 1] && s[(*i) + 1] && s[(*i) - 1] == s[(*i) + 1]
			&& s[(*i)] == c)
			ret[(*j)++] = 31;
		return (1);
	}
	return (0);
}

char	*add_space(char *s)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(2 * ft_strlen(s) + spaces_to_add(s) + 15);
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == 34 || s[i] == 39)
			skip_and_copy(s, ret, &i, &j);
		if (s[i] && !space_func(s, ret, &i, &j))
			ret[j++] = s[i++];
	}
	ret[j] = 0;
	return (ret);
}

char	*new_str(char *str)
{
	char	*ret;
	char	*tmp;

	ret = expand(str);
	free(str);
	tmp = remove_spaces(ret);
	free(ret);
	ret = add_space(tmp);
	free(tmp);
	return (ret);
}
