/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:02:42 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/21 15:46:53 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd_path(char *cmd)
{
	char	*cmd_path;
	char	*tmp;
	char	**path;
	int		i;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	i = 0;
	path = ft_split(getenv("PATH"), ':');
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
		{
			free_tab((void **)path);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_tab((void **)path);
	return (NULL);
}

void	exec_cmd(t_data *data, t_cmd *cmd)
{
	cmd->cmd_path = get_cmd_path(cmd->argv[0]);
	if (cmd->cmd_path == NULL)
	{
		perror("command not found ");
		exit(126);
	}
	if (execve(cmd->cmd_path, cmd->argv, data->env_cpy) == -1)
	{
		perror("execve failed ");
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
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed ");
		g_sig.prompt_erreur = true;
	}
	else if (pid == 0)
	{
		exec_cmd(data, cmd);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) != 0)
			g_sig.prompt_erreur = true;
		signal(SIGINT, sig_handler);
	}
	return (0);
}
