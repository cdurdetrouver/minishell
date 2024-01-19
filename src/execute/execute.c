/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:10:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/19 01:37:26 by gbazart          ###   ########.fr       */
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
	ft_save_fd(data->cmd, data);
	if (data->cmd->next)
		execute_pipe(data->cmd, data);
	else
		exec_one(data->cmd, data);
	ft_restore_fd(data->cmd, data);
}
