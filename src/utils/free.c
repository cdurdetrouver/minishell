/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/26 00:34:08 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env *lst)
{
	t_env	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		free(lst->key);
		free(lst->value);
		free(lst);
		lst = tmp;
	}
}

void	free_file(t_redir *lst)
{
	t_redir	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		free(lst->file);
		free(lst);
		lst = tmp;
	}
}

void	free_cmd(t_cmd *lst)
{
	t_cmd	*tmp;

	if (!lst)
		return ;
	lst = cmdfirst(lst);
	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		tokenclear(lst->token);
		free(lst->cmd);
		free_tab((void **)lst->argv);
		free_file(lst->file);
		lst->cmd_path = NULL;
		if (lst)
			free(lst);
		lst = tmp;
	}
}

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
