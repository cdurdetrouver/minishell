/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:10:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/16 16:53:11 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_one(t_cmd *cmd, t_data *data)
{
	if (is_builtin(cmd->cmd) == true)
		builtin(cmd, data);
	else
		exec(data, cmd);
}

void	execute(t_data *data)
{
	t_cmd	*cmd;
	int		save_fd[2];

	save_fd[0] = dup(STDIN_FILENO);
	save_fd[1] = dup(STDOUT_FILENO);
	cmd = data->cmd;
	if (cmd->next)
		execute_pipe(cmd, data);
	else
		exec_one(cmd, data);
	dup2(save_fd[0], STDIN_FILENO);
	dup2(save_fd[1], STDOUT_FILENO);
	close(save_fd[0]);
	close(save_fd[1]);
}
