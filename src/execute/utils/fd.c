/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:00:46 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/17 18:08:27 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_save_fd(t_cmd *cmd, t_data *data)
{
	t_cmd	*first;
	t_cmd	*last;

	first = cmdfirst(cmd);
	last = cmdlast(cmd);
	if (first->fd_in != 0)
		data->save_fd[0] = dup(STDIN_FILENO);
	else
		data->save_fd[0] = -1;
	if (last->fd_out != 1)
		data->save_fd[1] = dup(STDOUT_FILENO);
	else
		data->save_fd[1] = -1;
}

void	ft_restore_fd(t_data *data)
{
	if (data->save_fd[0] != -1)
	{
		dup2(data->save_fd[0], STDIN_FILENO);
		close(data->save_fd[0]);
	}
	if (data->save_fd[1] != -1)
	{
		dup2(data->save_fd[1], STDOUT_FILENO);
		close(data->save_fd[1]);
	}
}