/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:13:23 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/13 00:18:04 by gbazart          ###   ########.fr       */
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
	list->cmd = content;
	list->next = NULL;
	list->prev = NULL;
	list->token = token;
	list->fd_in = -1;
	list->fd_out = -1;
	return (list);
}

void	cmdclear(t_cmd *lst)
{
	t_cmd	*tmp;

	if (!lst)
		return ;
	lst = cmdfirst(lst);
	while (lst)
	{
		tmp = lst->next;
		free(lst->cmd);
		tokenclear(lst->token);
		free_tab((void **)lst->argv);
		if (lst->cmd_path)
			free(lst->cmd_path);
		free(lst);
		lst = tmp;
	}
}
