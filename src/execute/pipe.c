/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:03:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/26 01:22:02 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_test(t_cmd *cmd, t_data *data)
{
	int	code;

	if (is_builtin(cmd->argv[0]) == true)
	{
		code = builtin(cmd, data);
		free_and_close(data, cmd);
		exit(code);
	}
	else
		exec_cmd(data, cmd);
}

void	wait_for_children(t_cmd *cmd)
{
	int	status;

	while (cmd)
	{
		if (cmd->pid > 0)
		{
			waitpid(cmd->pid, &status, 0);
			if (WEXITSTATUS(status) != 0)
				g_exit_code = WEXITSTATUS(status);
		}
		cmd = cmd->next;
	}
	signal(SIGINT, sig_handler);
}

void	child(t_cmd *cmd, t_data *data)
{
	if (cmd_open(cmd) == -1)
		return ;
	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		perror("fork failed ");
		g_exit_code = 1;
	}
	else if (cmd->pid == 0)
	{
		close(cmd->fd[0]);
		dup2(cmd->fd[1], STDOUT_FILENO);
		close(cmd->fd[1]);
		exec_test(cmd, data);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		close(cmd->fd[1]);
		dup2(cmd->fd[0], STDIN_FILENO);
		close(cmd->fd[0]);
	}
}

void	end_pipe(t_cmd *cmd, t_data *data)
{
	if (cmd_open(cmd) == -1)
		return ;
	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		perror("fork failed ");
		g_exit_code = 1;
	}
	else if (cmd->pid == 0)
	{
		if (cmd->fd[0] > 0)
		{
			dup2(cmd->fd[0], STDIN_FILENO);
			close(cmd->fd[0]);
		}
		if (cmd->fd[1] > 1)
		{
			dup2(cmd->fd[1], STDOUT_FILENO);
			close(cmd->fd[1]);
		}
		exec_test(cmd, data);
		exit(0);
	}
}

int	execute_pipe(t_cmd *cmd, t_data *data)
{
	while (cmd->next)
	{
		if (pipe(cmd->fd) == -1)
		{
			ft_putstr_fd("pipe failed\n", 2);
			return (-1);
		}
		child(cmd, data);
		cmd = cmd->next;
	}
	end_pipe(cmd, data);
	// ft_close_fd(data->cmd);
	wait_for_children(data->cmd);
	return (1);
}
