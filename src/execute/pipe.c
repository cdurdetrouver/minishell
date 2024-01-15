/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:03:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/15 18:11:52 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_test(t_cmd *cmd, t_data *data)
{
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		echo(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "cd") == 0)
		cd(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		export_builtin(cmd->argv, data->env_cpy);
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		unset(cmd->argv);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		env(data->env_cpy);
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		exit_builtin(cmd->argv, data);
	return (0);
}

void	exec_test(t_cmd *cmd, t_data *data)
{
	if (is_builtin(cmd->cmd) == true)
		builtin_test(cmd, data);
	else
		exec_cmd(data, cmd);
}

void	child(t_cmd *cmd, t_data *data)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 1)
		exit(1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec_test(cmd, data);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		signal(SIGINT, sig_handler);
	}
}

void	end(t_cmd *cmd, t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 1)
		exit(1);
	if (pid == 0)
	{
		exec_test(cmd, data);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

int	execute_pipe(t_cmd *cmd, t_data *data)
{
	int		filein;
	int		fileout;
	t_cmd	*first;
	t_cmd	*last;

	first = cmdfirst(cmd);
	last = cmdlast(cmd);
	filein = first->fd_in;
	fileout = last->fd_out;
	dup2(filein, STDIN_FILENO);
	while (cmd->next)
	{
		child(cmd, data);
		cmd = cmd->next;
	}
	dup2(fileout, STDOUT_FILENO);
	end(cmd, data);
	return (1);
}
