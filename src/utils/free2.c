/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 00:33:22 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 00:16:32 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief free a token list.
 *
 * @param lst (t_token *) token list to free.
 */
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

/**
 * @brief free for the end of the program.
 *
 * @param data (t_data *) free data struct
 */
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
 */
void	free_start(t_data *data)
{
	free(data->line);
	if (data->cmd)
		free_cmd(data->cmd);
	data->cmd = NULL;
}
