/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:21:52 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/29 17:57:20 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief create a file for >.
 *
 * @param file	(char *)
 * @return (int) fd
 */
int	ft_open(t_redir *file)
{
	if (file->type == RD_GREAT)
		return (ft_append(file->file));
	else if (file->type == RD_LESS)
		return (ft_heredoc(file->file));
	else if (file->type == R_GREAT)
		return (ft_create(file->file));
	else if (file->type == R_LESS)
		return (ft_read(file->file));
	return (-2);
}

/**
 * @brief open the file for one command.
 *
 * @param cmd (t_cmd *)
 * @return (int) 1 if it works, 0 if don't.
 */
int	cmd_open(t_cmd *cmd)
{
	t_redir	*file;
	int		fd;

	file = cmd->file;
	while (file)
	{
		fd = ft_open(file);
		if (fd == -1)
			return (g_exit_code = 1, -1);
		if (file->type == R_LESS || file->type == RD_LESS)
		{
			if (cmd->fd[0][0] > 0)
				close(cmd->fd[0][0]);
			cmd->fd[0][0] = fd;
		}
		else if (file->type == R_GREAT || file->type == RD_GREAT)
		{
			if (cmd->fd[0][1] > 1)
				close(cmd->fd[0][1]);
			cmd->fd[0][1] = fd;
		}
		file = file->next;
	}
	return (1);
}

/**
 * @brief close all fd.
 *
 * @param cmd (t_cmd *)
 */
void	ft_close_fd(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmdfirst(cmd);
	while (tmp)
	{
		if (tmp->fd[0][0] > 0)
			close(tmp->fd[0][0]);
		if (tmp->fd[0][1] > 1)
			close(tmp->fd[0][1]);
		if (tmp->fd[1][0] > 0)
			close(tmp->fd[1][0]);
		if (tmp->fd[1][1] > 1)
			close(tmp->fd[1][1]);
		tmp = tmp->next;
	}
}
