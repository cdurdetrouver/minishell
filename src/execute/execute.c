/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:10:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/26 18:39:21 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect(t_cmd *cmd)
{
	if (cmd->fd[0][0] > 0)
	{
		if (dup2(cmd->fd[0][0], STDIN_FILENO) == -1)
		{
			ft_putstr_fd("dup2 failled\n", 2);
			close(cmd->fd[0][0]);
			return (-1);
		}
	}
	if (cmd->fd[0][1] > 1)
	{
		if (dup2(cmd->fd[0][1], STDOUT_FILENO) == -1)
		{
			ft_putstr_fd("dup2 failled\n", 2);
			close(cmd->fd[0][1]);
			return (-1);
		}
	}
	return (0);
}

void	exec_one(t_cmd *cmd, t_data *data)
{
	if (cmd_open(cmd) == -1)
	{
		g_exit_code = 1;
		return ;
	}
	if (redirect(cmd) == -1)
		return ;
	if (is_builtin(cmd->argv[0]) == true)
		builtin(cmd, data);
	else
		exec(data, cmd);
	if (cmd->fd[0][0] > 0)
		close(cmd->fd[0][0]);
	if (cmd->fd[0][1] > 1)
		close(cmd->fd[0][1]);
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
