/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:03:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 03:03:37 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_test(t_cmd *cmd, t_data *data)
{
	if (is_builtin(cmd->argv[0]) == true)
	{
		exit(builtin(cmd, data));
	}
	else
		exec_cmd(data, cmd);
}

void	set_redir_parent(int fd[2], t_cmd *cmd)
{
	close(fd[1]);
	if (cmd->file_in.type != R_NONE)
	{
		close(fd[0]);
		dup2(cmd->file_in.fd, STDIN_FILENO);
		close(cmd->file_in.fd);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	set_redir_child(int fd[2], t_cmd *cmd)
{
	close(fd[0]);
	if (cmd->file_out.type != R_NONE)
	{
		close(fd[1]);
		dup2(cmd->file_out.fd, STDOUT_FILENO);
		close(cmd->file_out.fd);
	}
	else
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
}

int	open_file(t_cmd *cmd)
{
	if (cmd->file_out.type != R_NONE)
		cmd->file_out.fd = ft_open(cmd, &cmd->file_out);
	else
		cmd->file_out.fd = -2;
	if (cmd->file_in.type != R_NONE)
		cmd->file_in.fd = ft_open(cmd, &cmd->file_in);
	else
		cmd->file_in.fd = -2;
	if (cmd->file_out.fd == -1 || cmd->file_in.fd == -1)
	{
		if (cmd->file_out.fd != -2)
			close(cmd->file_out.fd);
		if (cmd->file_in.fd != -2)
			close(cmd->file_in.fd);
		g_sig.prompt_erreur = true;
		g_sig.exit_code = 1;
		return (-1);
	}
	return (1);
}

void	child(t_cmd *cmd, t_data *data, int fd[2])
{
	pid_t	pid;

	if (open_file(cmd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed ");
		g_sig.prompt_erreur = true;
		return ;
	}
	else if (pid == 0)
	{
		close(fd[0]);
		set_redir_child(fd, cmd);
		exec_test(cmd, data);
		exit(167);
	}
	else
	{
		close(fd[1]);
		set_redir_parent(fd, cmd);
	}
}

void	wait_for_children(void)
{
	pid_t	pid;
	int		status;

	while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
	{
		if (WEXITSTATUS(status) != 0)
		{
			g_sig.prompt_erreur = true;
			g_sig.exit_code = WEXITSTATUS(status);
		}
	}
}

void	end(t_cmd *cmd, t_data *data, int fd[2])
{
	set_redir_parent(fd, cmd);
	exec_one(cmd, data);
}

int	execute_pipe(t_cmd *cmd, t_data *data)
{
	int	fd[2];

	if (cmd->file_in.type != R_NONE)
	{
		cmd->file_in.fd = ft_open(cmd, &cmd->file_in);
		if (cmd->file_in.fd == -1)
		{
			g_sig.exit_code = 1;
			cmd = cmd->next;
		}
		else
		{
			dup2(cmd->file_in.fd, STDIN_FILENO);
			close(cmd->file_in.fd);
		}
	}
	while (cmd->next)
	{
		if (pipe(fd) == -1)
		{
			perror("pipe failed ");
			g_sig.prompt_erreur = true;
			return (-1);
		}
		child(cmd, data, fd);
		cmd = cmd->next;
	}
	end(cmd, data, fd);
	wait_for_children();
	return (1);
}
