/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:00:46 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/21 22:40:19 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_save_fd(t_cmd *cmd, t_data *data)
{
	t_cmd	*first;

	first = cmdfirst(cmd);
	data->save_fd[0] = dup(STDIN_FILENO);
	data->save_fd[1] = dup(STDOUT_FILENO);
	if (first->file_in.type != R_NONE)
	{
		first->file_in.fd = ft_open(first, &first->file_in);
		dup2(first->file_in.fd, STDIN_FILENO);
		close(first->file_in.fd);
	}
}

void	ft_restore_fd(t_data *data)
{
	dup2(data->save_fd[0], STDIN_FILENO);
	close(data->save_fd[0]);
	dup2(data->save_fd[1], STDOUT_FILENO);
	close(data->save_fd[1]);
}
