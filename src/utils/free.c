/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 00:18:05 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief free a env list.
 *
 * @param lst (t_env *) env list to free.
 */
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

/**
 * @brief free a file list.
 *
 * @param lst (t_redir *) file list to free.
 */
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

/**
 * @brief free a cmd list.
 *
 * @param lst (t_cmd *) cmd list to free.
 */
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

/**
 * @brief free a tab alloc with malloc.
 *
 *@param ptr
 */
void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
