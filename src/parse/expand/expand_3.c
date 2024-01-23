/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:49:46 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/23 03:00:27 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_expand(t_exp *exp)
{
	t_exp	*ptr;

	ptr = exp;
	while (exp)
	{
		printf("%d : %s len : %zu\n", exp->index, exp->var,
			ft_strlen(exp->var));
		exp = exp->next;
	}
	exp = ptr;
}

void	expand_func_1(t_exp *exp, char *ret, int *j)
{
	char	*to_copy;
	int		k;
	char	*tmp;

	if (ft_strcmp(exp->var, "?") == 0)
	{
		tmp = ft_itoa(g_sig.exit_code);
		k = 0;
		while (tmp[k])
			ret[(*j)++] = tmp[k++];
		free(tmp);
	}
	else
	{
		to_copy = getenv(exp->var);
		if (to_copy)
		{
			k = 0;
			while (to_copy[k])
				ret[(*j)++] = to_copy[k++];
		}
		else
			ret[(*j)++] = '$';
	}
}

char	*expand_func_2(int *i, int *j, char *s, char *ret)
{
	while (s[*i])
		ret[(*j)++] = s[(*i)++];
	ret[(*j)] = 0;
	return (ret);
}

void	expand_func_3(char *s, int *i)
{
	static int	in = 0;

	if (s[*i] && s[*i] == 34)
	{
		if (!in)
			in = 1;
		else
			in = 0;
	}
	if (s[*i] && s[*i] == 39 && !in)
		skip_quotes(s, i);
	(*i)++;
}

char	*expand(char *s)
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
	ret = malloc(memory_needed(s, exp));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (exp)
	{
		while (s[i] && i < exp->index)
			ret[j++] = s[i++];
		expand_func_1(exp, ret, &j);
		i += ft_strlen(exp->var) + 1;
		exp = exp->next;
	}
	return (expclear(ptr), expand_func_2(&i, &j, s, ret));
}
