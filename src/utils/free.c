/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:36:15 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
 * @param data
 */
void	free_end(t_data *data)
{
	free_tab((void **)data->env_cpy);
}

/**
 * @brief free for each loop of the program.
 *
 * @param data
 */
void	free_start(t_data *data)
{
	free(data->line);
}
