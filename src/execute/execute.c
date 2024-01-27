/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:10:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 15:32:32 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief redirect the fd.
 *
 * @param cmd (t_cmd *)
 */
static int	redirect(t_cmd *cmd)
{
	if (cmd->fd[0][0] > 0)
	{
		if (dup2(cmd->fd[0][0], STDIN_FILENO) == -1)
		{
			ft_putstr_fd("dup2 failled\n", 2);
			return (-1);
		}
	}
	if (cmd->fd[0][1] > 1)
	{
		if (dup2(cmd->fd[0][1], STDOUT_FILENO) == -1)
		{
			ft_putstr_fd("dup2 failled\n", 2);
			return (-1);
		}
	}
	return (0);
}

/**
 * @brief close all fd.
 *
 * @param cmd (t_cmd *)
 */
static void	close_all(t_cmd *cmd)
{
	if (cmd->fd[0][0] > 0)
		close(cmd->fd[0][0]);
	if (cmd->fd[0][1] > 1)
		close(cmd->fd[0][1]);
}

/**
 * @brief execute one command.
 *
 * @param cmd (t_cmd *)
 * @param data (t_data *)
 */
static void	exec_one(t_cmd *cmd, t_data *data)
{
	if (cmd_open(cmd) == -1)
	{
		close_all(cmd);
		g_exit_code = 1;
		return ;
	}
	if (redirect(cmd) == -1)
	{
		close_all(cmd);
		return ;
	}
	close_all(cmd);
	if (!cmd->argv[0])
		return ;
	if (is_builtin(cmd->argv[0]) == true)
		builtin(cmd, data, 1);
	else
		exec(data, cmd);
}

void	execute(t_data *data)
{
	g_exit_code = 0;
	ft_save_fd(data);
	if (data->cmd->next)
		execute_pipe(data->cmd, data);
	else
		exec_one(data->cmd, data);
	ft_restore_fd(data);
}
