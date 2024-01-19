/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:00:46 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/19 03:36:11 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_save_fd(t_cmd *cmd, t_data *data)
{
	t_cmd	*first;
	t_cmd	*last;

	first = cmdfirst(cmd);
	last = cmdlast(cmd);
	if (first->file_in.type != R_NONE)
	{
		data->save_fd[0] = dup(STDIN_FILENO);
		first->file_in.fd = ft_open(first, &first->file_in);
		dup2(first->file_in.fd, STDIN_FILENO);
		close(first->file_in.fd);
	}
	if (last->file_out.type != R_NONE)
	{
		data->save_fd[1] = dup(STDOUT_FILENO);
		last->file_out.fd = ft_open(last, &last->file_out);
	}
}

void	ft_restore_fd(t_cmd *cmd, t_data *data)
{
	t_cmd *first;
	t_cmd *last;

	first = cmdfirst(cmd);
	last = cmdlast(cmd);
	if (first->file_in.type != R_NONE)
	{
		dup2(data->save_fd[0], STDIN_FILENO);
		close(data->save_fd[0]);
	}
	if (last->file_out.type != R_NONE)
	{
		dup2(data->save_fd[1], STDOUT_FILENO);
		close(data->save_fd[1]);
	}
}
