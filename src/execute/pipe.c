/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:03:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/19 03:33:41 by gbazart          ###   ########.fr       */
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
	{
		builtin_test(cmd, data);
		exit(0);
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
		cmd->file_in.fd = ft_open(cmd, &cmd->file_in);
		dup2(cmd->file_in.fd, STDIN_FILENO);
		close(cmd->file_in.fd);
	}
	else
		dup2(fd[0], STDIN_FILENO);
}

void	set_redir_child(int fd[2], t_cmd *cmd)
{
	close(fd[0]);
	if (cmd->file_out.type != R_NONE)
	{
		close(fd[1]);
		cmd->file_out.fd = ft_open(cmd, &cmd->file_out);
		dup2(cmd->file_out.fd, STDOUT_FILENO);
		close(cmd->file_out.fd);
	}
	else
		dup2(fd[1], STDOUT_FILENO);
}

void	child(t_cmd *cmd, t_data *data)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	if (pipe(fd) == -1)
		perror("pipe failed ");
	pid = fork();
	if (pid == 0)
	{
		set_redir_child(fd, cmd);
		exec_test(cmd, data);
	}
	else
	{
		set_redir_parent(fd, cmd);
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) != 0)
			g_sig.prompt_erreur = true;
		signal(SIGINT, sig_handler);
	}
}

void	end(t_cmd *cmd, t_data *data)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	if (pipe(fd) == -1)
		perror("pipe failed ");
	pid = fork();
	if (pid == 0)
	{
		exec_test(cmd, data);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) != 0)
			g_sig.prompt_erreur = true;
		signal(SIGINT, sig_handler);
	}
}

int	execute_pipe(t_cmd *cmd, t_data *data)
{
	t_cmd	*last;

	last = cmdlast(cmd);
	while (cmd->next)
	{
		child(cmd, data);
		cmd = cmd->next;
	}
	if (last->file_out.type != R_NONE)
	{
		dup2(last->file_out.fd, STDOUT_FILENO);
		close(last->file_out.fd);
	}
	end(cmd, data);
	return (1);
}
