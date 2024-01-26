/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:21:52 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/26 18:28:25 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_heredoc(char *limiter)
{
	char	*line;
	char	filename[] = "/tmp/heredoc_file";
	int		fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open failed");
		return (-1);
	}
	while ((line = readline("> ")) != NULL)
	{
		if (ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	fd = open(filename, O_RDWR);
	return (fd);
}

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
