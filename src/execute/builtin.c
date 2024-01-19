/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:15:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/18 19:49:07 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief check if the command is a builtin and execute it.
 *
 * @param cmd (t_cmd *)
 * @param data (t_data *)
 *
 * @return int 1 if builtin, 0 if not
 */
int	builtin(t_cmd *cmd, t_data *data)
{
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		echo(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "cd") == 0)
		cd(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		export_builtin(cmd->argv, data->env_cpy);
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		unset(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		env(data->env_cpy);
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		exit_builtin(cmd->argv, data);
	return (0);
}
