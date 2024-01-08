/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:43:31 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/07 20:30:59 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Execute the command
 *
 * @param cmd t_cmd
 * @return 0 if works, 1 if not
 */
int	execute(t_cmd *cmd)
{
	if (cmd->name == NULL)
		return (0);
	if (ft_strcmp(cmd->name, "echo") == 0)
		echo(cmd);
	else if (ft_strcmp(cmd->name, "cd") == 0)
		cd(cmd);
	return (0);
}
