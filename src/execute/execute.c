/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:10:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/12 17:16:28 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec(t_data *data, t_cmd *cmd)
{
	char	**path;
	char	*temp;
	int		i;
	bool	find;

	i = 0;
	find = false;
	path = ft_split(getenv("PATH"), ':');
	if (!execve(cmd->cmd, cmd->argv, data->env_cpy))
		return (1);
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		temp = ft_strjoin2(temp, cmd->cmd);
		if (!execve(temp, cmd->argv, data->env_cpy))
		{
			find = true;
			break ;
		}
		free(temp);
		i++;
	}
	free_tab((void **)path);
	if (find == false)
	{
		printf("%s : cmd not found\n", cmd->cmd);
		g_sig.code_prompt = 1;
	}
	return (1);
}

int	execute(t_data *data)
{
	t_cmd	*cmd;
	pid_t	pid;

	cmd = data->cmd;
	while (cmd)
	{
		if (is_builtin(cmd->cmd) == true)
			builtin(cmd->argv, data, 1);
		else
		{
			pid = fork();
			if (pid == -1)
				print_error("pid");
			else if (pid == 0)
			{
				exec(data, cmd);
			}
			else
			{
				signal(SIGINT, SIG_IGN);
				waitpid(pid, NULL, 0);
				signal(SIGINT, sigint_handler);
			}
		}
		cmd = cmd->next;
	}
	return (1);
}
