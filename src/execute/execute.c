/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:10:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/15 17:51:13 by gbazart          ###   ########.fr       */
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

	cmd = data->cmd;
	if (has_pipe(cmd) == true)
	{
		// printf("pipe\n");
		// printf("%s %s\n", cmd->cmd, cmd->next->cmd);
		fflush(stdout);
		execute_pipe(cmd, data);
	}
	else
		exec_one(cmd, data);
}
