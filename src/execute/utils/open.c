/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:21:52 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/19 00:43:19 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_create(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		perror("minishell");
	return (fd);
}

int	ft_append(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		perror("minishell");
	return (fd);
}

int	ft_read(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("minishell");
	return (fd);
}

int	ft_heredoc(char *file)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) < 0)
		perror("minishell");
	close(fd[1]);
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, file))
			break ;
		ft_putendl_fd(line, fd[0]);
		free(line);
	}
	if (line)
		free(line);
	return (fd[0]);
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
	return (-1);
}
