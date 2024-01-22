/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:31:16 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/22 13:46:53 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenadd_back(t_token **lst, t_token *new)
{
	t_token	*l;

	if (*lst)
	{
		l = tokenlast(*lst);
		if (l)
		{
			l->next = new;
			l->next->prev = l;
		}
	}
}

int	tokensize(t_token *lst)
{
	int		i;
	t_token	*l;

	i = 0;
	l = lst;
	while (l != NULL)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_token	*tokennew(char *content, t_type type)
{
	t_token	*list;

	list = malloc(sizeof(t_token));
	if (!list)
		return (NULL);
	list->content = NULL;
	if (content)
	{
		list->content = ft_strdup(content);
		if (!list->content)
		{
			free(list);
			return (NULL);
		}
	}
	list->type = type;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	tokenclear(t_token *lst)
{
	t_token	*tmp;

	lst = tokenfirst(lst);
	while (lst->next)
	{
		tmp = lst->next;
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = tmp;
	}
}

int	type_is_sep(t_type type)
{
	if (type == PIPE || type == D_PIPE || type == D_GREAT || type == D_LESS
		|| type == SEMICOLON || type == ESPER || type == BSLASH || type == GREAT
		|| type == LESS)
		return (1);
	return (0);
}
