/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:16:23 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/07 20:31:08 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Change the current working directory
 *
 * @param args t_cmd
 */
int	cd(t_cmd *cmd)
{
	if (cmd->nbr_arg == 1)
	{
		if (chdir(getenv("HOME")) == -1)
			printf("cd: HOME not set\n");
	}
	else if (cmd->nbr_arg == 2)
	{
		if (chdir(cmd->args[1]) == -1)
			printf("cd: %s: No such file or directory\n", cmd->args[1]);
	}
	return (0);
}
