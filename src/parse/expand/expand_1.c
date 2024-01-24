/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:19:41 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/24 15:26:10 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exp	*expnew(char *content, int index)
{
	t_exp	*exp;

	exp = malloc(sizeof(t_exp));
	if (!exp)
		return (NULL);
	exp->index = index;
	exp->var = content;
	exp->next = NULL;
	return (exp);
}

t_exp	*explast(t_exp *exp)
{
	if (!exp || !exp->next)
		return (exp);
	exp = exp->next;
	return (explast(exp));
}

void	expclear(t_exp *exp)
{
	t_exp	*tmp;

	while (exp)
	{
		tmp = exp->next;
		free(exp->var);
		free(exp);
		exp = tmp;
	}
}

void	expadd_back(t_exp **lst, t_exp *new)
{
	t_exp	*l;

	if (*lst)
	{
		l = explast(*lst);
		if (l)
			l->next = new;
	}
}

char	*get_var(char *str, t_env *env)
{
	char	*s;
	int		i;
	char	*r;

	if (!str || !env)
		return (NULL);
	if (!ft_strncmp(str, "?", ft_strlen(str) + 2))
		return (ft_itoa(g_sig.exit_code));
	i = -1;
	s = malloc(ft_strlen(str) + 1);
	while (str[++i])
		s[i] = str[i];
	s[i] = 0;
	while (env)
	{
		if (!ft_strncmp(s, env->key, ft_strlen(s) + 1))
		{
			r = ft_substr(env->value, 0, ft_strlen(env->value));
			return (free(s), r);
		}
		env = env->next;
	}
	return (free(s), NULL);
}
