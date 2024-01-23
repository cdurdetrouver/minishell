/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:10:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 02:52:26 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_one(t_cmd *cmd, t_data *data)
{
	if (cmd->file_in.type != R_NONE)
	{
		cmd->file_in.fd = ft_open(cmd, &cmd->file_in);
		if (cmd->file_in.fd == -1)
		{
			g_sig.exit_code = 1;
			return ;
		}
		dup2(cmd->file_in.fd, STDIN_FILENO);
		close(cmd->file_in.fd);
	}
	if (cmd->file_out.type != R_NONE)
	{
		cmd->file_out.fd = ft_open(cmd, &cmd->file_out);
		if (cmd->file_out.fd == -1)
		{
			g_sig.exit_code = 1;
			return ;
		}
		dup2(cmd->file_out.fd, STDOUT_FILENO);
		close(cmd->file_out.fd);
	}
	if (is_builtin(cmd->argv[0]) == true)
		builtin(cmd, data);
	else
		exec(data, cmd);
}

void	execute(t_data *data)
{
	g_sig.exit_code = 0;
	ft_save_fd(data);
	if (data->cmd->next)
		execute_pipe(data->cmd, data);
	else
		exec_one(data->cmd, data);
	ft_restore_fd(data);
}
