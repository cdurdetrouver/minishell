/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 15:20:10 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenclear(t_token *lst)
{
	t_token	*tmp;

	lst = tokenfirst(lst);
	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		if (lst->content)
		{
			free(lst->content);
		}
		free(lst);
		lst = tmp;
	}
}

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
		// if (lst->cmd_path != NULL)
		// 	free(lst->cmd_path);
		lst->cmd_path = NULL;
		free(lst);
		lst = tmp;
	}
}

/**
 * @brief free a tab alloc with malloc.
 *
 * @param tab (void **) tab to free.
 */
void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_end(t_data *data)
{
	free_tab((void **)data->env_cpy);
	rl_clear_history();
	free_env(data->env);
}

/**
 * @brief free for each loop of the program.
 *
 * @param data (t_data *) free data struct
 * @param prompt (char *) free the prompt
 */
void	free_start(t_data *data)
{
	free(data->line);
	if (data->cmd)
		free_cmd(data->cmd);
	data->cmd = NULL;
}

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
