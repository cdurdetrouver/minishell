/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:49:46 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/29 13:07:10 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_func_1(t_exp *exp, t_env *env, char *ret, int *j)
{
	char	*to_copy;
	int		k;

	k = 0;
	to_copy = get_var(exp->var, env);
	if (to_copy)
	{
		k = 0;
		while (to_copy[k])
			ret[(*j)++] = to_copy[k++];
		free(to_copy);
	}
}

char	*expand_func_2(int *i, int *j, char *s, char *ret)
{
	while (s[*i])
		ret[(*j)++] = s[(*i)++];
	ret[(*j)] = 0;
	return (ret);
}

void	expand_func_3(char *s, int *i, int *in)
{
	if (s[*i] && s[*i] == 34)
	{
		if (!*in)
			*in = 1;
		else
			*in = 0;
	}
	if (s[*i] && s[*i] == 39 && !*in)
		skip_quotes(s, i);
	(*i)++;
}

char	*expand(char *s, t_env *env)
{
	int		i;
	int		j;
	char	*ret;
	t_exp	*exp;
	t_exp	*ptr;

	exp = init_expand(s);
	if (!exp)
		return (ft_strdup(s));
	ptr = exp;
	ret = malloc(memory_needed(s, env, exp));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (exp)
	{
		while (s[i] && i < exp->index)
			ret[j++] = s[i++];
		expand_func_1(exp, env, ret, &j);
		i += ft_strlen(exp->var) + 1;
		exp = exp->next;
	}
	return (expclear(ptr), expand_func_2(&i, &j, s, ret));
}
