/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:03:39 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/14 22:52:55 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pipe(t_cmd *cmd, t_data *data)
{
	int		fd[2];
	pid_t	pid;

	(void)cmd;
	(void)data;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		printf("pipe\n");
		exit(0);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[1]);
		printf("pipe\n");
		waitpid(pid, NULL, 0);
	}
	return (1);
}
