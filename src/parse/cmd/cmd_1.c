/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:13:23 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/25 10:51:49 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmdadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*l;

	if (*lst)
	{
		l = cmdlast(*lst);
		if (l)
		{
			l->next = new;
			l->next->prev = l;
		}
	}
}

int	cmdsize(t_cmd *lst)
{
	int		i;
	t_cmd	*l;

	i = 0;
	l = lst;
	while (l != NULL)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_cmd	*cmdnew(char *content, t_token *token)
{
	t_cmd	*list;

	list = malloc(sizeof(t_cmd));
	if (!list)
		return (NULL);
	list->cmd = ft_strdup(content);
	list->pid = 0;
	list->next = NULL;
	list->prev = NULL;
	list->fd[0] = 0;
	list->fd[1] = 1;
	list->token = token;
	list->file = NULL;
	return (list);
}
