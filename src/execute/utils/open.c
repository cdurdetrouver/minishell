/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:21:52 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/24 00:39:32 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_create(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		perror(file);
	return (fd);
}

int	ft_append(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		perror(file);
	return (fd);
}

int	ft_read(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror(file);
	return (fd);
}

int	ft_heredoc(char *file)
{
	char	*line;
	int		fd[2];
	pid_t	reader;

	if (pipe(fd) == -1)
		perror(file);
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (1)
		{
			line = readline("> ");
			if (!ft_strcmp(line, file))
				break ;
			ft_putendl_fd(line, fd[1]);
			free(line);
		}
		if (line)
			free(line);
	}
	else
	{
		close(fd[1]);
		wait(NULL);
		return (fd[0]);
	}
	return (-1);
}

int	ft_open(t_cmd *cmd, t_redir *file)
{
	t_cmd	*first;
	t_cmd	*last;

	first = cmdfirst(cmd);
	last = cmdlast(cmd);
	if (file->type == R_NONE && file == &first->file_in)
		return (0);
	else if (file->type == R_NONE && file == &last->file_out)
		return (1);
	else if (file->type == RD_GREAT)
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
	fd = 0;
	while (file)
	{
		fd = ft_open(cmd, file);
		if (fd == -1)
			return (-1);
		if (file->type == R_LESS || file->type == RD_LESS)
		{
			if (cmd->fd[0] > 0)
				close(cmd->fd[0]);
			cmd->fd[0] = fd;
		}
		else if (file->type == R_GREAT || file->type == RD_GREAT)
		{
			if (cmd->fd[1] > 1)
				close(cmd->fd[1]);
			cmd->fd[1] = fd;
		}
		file = file->next;
	}
	return (1);
}
