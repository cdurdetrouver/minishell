/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:03:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/24 02:07:31 by gbazart          ###   ########.fr       */
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

void	wait_for_children(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	while (cmd)
	{
		waitpid(cmd->pid, &status, 0);
		if (WEXITSTATUS(status) != 0)
		{
			g_sig.prompt_erreur = true;
			g_sig.exit_code = WEXITSTATUS(status);
		}
		cmd = cmd->next;
	}
	signal(SIGINT, sig_handler);
}

void	ft_close_all_pipes(t_cmd *cmd)
{
	cmd = cmd_first(cmd);
	while (cmd->next)
	{
		if (cmd->fd[0] > 0)
			close(cmd->fd[0]);
		if (cmd->fd[1] > 1)
			close(cmd->fd[1]);
		cmd = cmd->next;
	}
}

int	init_cmd(t_cmd *cmd)
{
	cmd = cmd_first(cmd);
	while (cmd->next)
	{
		if (pipe(cmd->fd) == -1)
		{
			perror("pipe failed ");
			g_sig.prompt_erreur = true;
			g_sig.exit_code = 3;
			return (-1);
		}
		cmd = cmd->next;
	}
}

void	child(t_cmd *cmd, t_data *data)
{
	if (cmd_open(cmd) == -1)
		return ;
	else if (redirect(cmd) == -1)
		return ;
	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		perror("fork failed ");
		g_sig.prompt_erreur = true;
	}
	else if (cmd->pid == 0)
		exec_test(cmd, data);
	else
	{
		signal(SIGINT, SIG_IGN);
		close(cmd->fd[1]);
	}
}

void	end(t_cmd *cmd, t_data *data)
{
	if (cmd_open(cmd) == -1)
		return ;
	else if (redirect(cmd) == -1)
		return ;
	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		perror("fork failed ");
		g_sig.prompt_erreur = true;
	}
	else if (cmd->pid == 0)
		exec_test(cmd, data);
	else
	{
		signal(SIGINT, SIG_IGN);
		close(cmd->fd[0]);
	}
}

int	execute_pipe(t_cmd *cmd, t_data *data)
{
	if (init_cmd(cmd) == -1)
		return (-1);
	while (cmd->next)
	{
		child(cmd, data);
		cmd = cmd->next;
	}
	end(cmd, data);
	ft_close_all_pipes(cmd);
	wait_for_children(cmd);
	return (1);
}
