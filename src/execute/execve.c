/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:02:42 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/25 19:16:22 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (false);
	return (S_ISDIR(statbuf.st_mode));
}

char	*get_cmd_path(t_data *data, char *cmd)
{
	char	*cmd_path;
	char	**path;
	int		i;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	i = 0;
	if (!ft_getenv(data->env, "PATH"))
		return (NULL);
	path = ft_split(ft_getenv(data->env, "PATH"), ':');
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin2(cmd_path, cmd);
		if (access(cmd_path, F_OK) == 0)
			return (free_tab((void **)path), cmd_path);
		free(cmd_path);
		i++;
	}
	return (free_tab((void **)path), NULL);
}

void	free_and_close(t_data *data, t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmdfirst(cmd);
	while (tmp)
	{
		if (tmp->fd[0] > 0)
			close(tmp->fd[0]);
		if (tmp->fd[1] > 1)
			close(tmp->fd[1]);
		if (tmp->cmd_path)
			free(tmp->cmd_path);
		tmp = tmp->next;
	}
	free_start(data);
	free_end(data);
	close(data->save_fd[0]);
	close(data->save_fd[1]);
}

void	exec_cmd(t_data *data, t_cmd *cmd)
{
	if (is_directory(cmd->argv[0]))
	{
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putstr_fd(": Is a directory\n", 2);
		free_and_close(data, cmd);
		exit(126);
	}
	cmd->cmd_path = get_cmd_path(data, cmd->argv[0]);
	if (cmd->cmd_path == NULL)
	{
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_and_close(data, cmd);
		exit(127);
	}
	free_tab((void **)data->env_cpy);
	data->env_cpy = env_to_tab(data->env);
	if (execve(cmd->cmd_path, cmd->argv, data->env_cpy) == -1)
	{
		perror("execve failed ");
		free_and_close(data, cmd);
		exit(127);
	}
	free_and_close(data, cmd);
	exit(0);
}

/**
 * @brief execute the command with execve.
 *
 * @param data (t_data *) data
 * @param cmd (t_cmd *) cmd
 * @return (int) 1 if it works, 0 if don't.
 */
int	exec(t_data *data, t_cmd *cmd)
{
	int	status;

	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		perror("fork failed ");
		g_exit_code = 1;
	}
	else if (cmd->pid == 0)
	{
		exec_cmd(data, cmd);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(cmd->pid, &status, 0);
		if (WEXITSTATUS(status) != 0)
			g_exit_code = WEXITSTATUS(status);
		signal(SIGINT, sig_handler);
	}
	return (0);
}
