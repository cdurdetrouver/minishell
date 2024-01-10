/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:16:17 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 16:49:51 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_data *data)
{
	pid_t	pid;
	char	**path;
	int		i;
	char	*tmp;

	i = 1;
	pid = fork();
	if (pid == -1)
		ft_printf("minishell: fork error\n");
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, NULL, 0);
		signal(SIGINT, SIG_DFL);
	}
	else
	{
		signal(SIGINT, sigint_handler);
		if (is_builtin(data->start->argv[0]))
			builtin(data->start->argv, data);
		else
		{
			path = ft_split(getenv("PATH"), ':');
			tmp = ft_strjoin(path[0], "/");
			tmp = ft_strjoin2(tmp, data->start->argv[0]);
			while (execve(tmp, data->start->argv, data->envp) == -1 && path[i])
			{
				free(tmp);
				tmp = ft_strjoin(path[i], "/");
				tmp = ft_strjoin2(tmp, data->start->argv[0]);
				i++;
			}
			free(tmp);
			if (!path[i])
				ft_printf("minishell: %s: command not found\n",
					data->start->argv[0]);
			free_tab(path);
		}
	}
}
