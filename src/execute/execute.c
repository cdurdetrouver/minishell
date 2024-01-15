/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:10:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/15 00:24:21 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_one(t_cmd *cmd, t_data *data)
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
		printf("pipe\n");
		execute_pipe(cmd, data);
	}
	else
		exec_one(cmd, data);
}