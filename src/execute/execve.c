/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:02:42 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/29 18:23:59 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief check if the command is a directory.
 * 
 * @param cmd (char *) cmd
 * @return (bool) true if it is, false if not.
*/
bool	is_directory(char *cmd)
{
	struct stat	buf;

	if (!cmd)
		return (false);
	if (!ft_strrchr(cmd, '/'))
		return (false);
	if (stat(cmd, &buf) == -1)
		return (false);
	if (S_ISDIR(buf.st_mode))
		return (true);
	if (S_ISREG(buf.st_mode))
		return (false);
	return (false);
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
	if (is_directory(cmd->argv[0]))
	{
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putstr_fd(": Is a directory\n", 2);
		free_and_close(data);
		exit(126);
	}
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
		signal(SIGQUIT, SIG_DFL);
		exec_cmd(data, cmd);
	}
	else
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, handle_sigquit);
		waitpid(cmd->pid, &status, 0);
		if (g_exit_code != 130 && g_exit_code != 131)
			g_exit_code = WEXITSTATUS(status);
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	return (0);
}
