/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:15:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/15 00:24:31 by gbazart          ###   ########.fr       */
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
	int	fd[2];

	fd[0] = dup(0);
	fd[1] = dup(1);
	if (cmd->fd_in != -1)
		dup2(cmd->fd_in, 0);
	if (cmd->fd_out != -1)
		dup2(cmd->fd_out, 1);
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		return (echo(cmd->argv));
	else if (ft_strcmp(cmd->argv[0], "cd") == 0)
		return (cd(cmd->argv));
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		return (pwd());
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		return (export_builtin(cmd->argv, data->env_cpy));
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		return (unset(cmd->argv));
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		return (env(data->env_cpy));
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		return (exit_builtin(cmd->argv, data));
	dup2(fd[0], 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
