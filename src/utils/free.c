/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/07 18:41:35 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_all(char *line, t_cmd *cmd)
{
	free(line);
	free(cmd->name);
	while (cmd->args)
	{
		free(cmd->args);
		cmd->args++;
	}
}
