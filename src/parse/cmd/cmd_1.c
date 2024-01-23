/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:13:23 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/23 12:24:21 by hlamnaou         ###   ########.fr       */
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
	list->next = NULL;
	list->prev = NULL;
	list->token = token;
	list->file_in.type = R_NONE;
	list->file_in.file = NULL;
	list->file_out.type = R_NONE;
	list->file_out.file = NULL;
	return (list);
}
