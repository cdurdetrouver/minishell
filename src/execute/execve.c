/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:02:42 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/28 01:12:12 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief sigquit heandler for child
 *
 * @param sig
 */
void	sigquit_handler(int sig)
{
	(void)sig;
	write(1, "Quit (core dumped)\n", 19);
	exit(1);
}

/**
 * @brief get the path of the command.
 *
 * @param data (t_data *) data
 * @param cmd (char *) cmd
 * @return (char *) path of the command
 */
static char	*get_cmd_path(t_data *data, char *cmd)
{
	char	*cmd_path;
	char	**path;
	int		i;

	if (!cmd)
		return (NULL);
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
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

/**
 * @brief free all and close for child process.
 *
 * @param data (t_data *) data
 */
void	free_and_close(t_data *data)
{
	free_start(data);
	free_end(data);
	close(data->save_fd[0]);
	close(data->save_fd[1]);
}

/**
 * @brief execute the command with execve.
 *
 * @param data (t_data *) data
 * @param cmd (t_cmd *) cmd
 */
void	exec_cmd(t_data *data, t_cmd *cmd)
{
	cmd->cmd_path = get_cmd_path(data, cmd->argv[0]);
	if (cmd->cmd_path == NULL)
	{
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_and_close(data);
		exit(127);
	}
	free_tab((void **)data->env_cpy);
	data->env_cpy = env_to_tab(data->env);
	if (execve(cmd->cmd_path, cmd->argv, data->env_cpy) == -1)
	{
		free(cmd->cmd_path);
		cmd->cmd_path = NULL;
		perror("execve failed ");
		free_and_close(data);
		exit(126);
	}
	free_and_close(data);
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
		signal(SIGQUIT, sigquit_handler);
		exec_cmd(data, cmd);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(cmd->pid, &status, 0);
		g_exit_code = WEXITSTATUS(status);
		signal(SIGINT, sig_handler);
	}
	return (0);
}
