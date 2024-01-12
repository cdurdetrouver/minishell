/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:19:41 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/11 16:14:08 by gbazart          ###   ########.fr       */
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
