/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:00:46 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/29 16:45:18 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief save stdin and stdout fd.
 *
 * @param data	(t_data *)
 */
void	ft_save_fd(t_data *data)
{
	data->save_fd[0] = dup(STDIN_FILENO);
	data->save_fd[1] = dup(STDOUT_FILENO);
}

/**
 * @brief restore stdin and stdout fd.
 *
 * @param data	(t_data *)
 */
void	ft_restore_fd(t_data *data)
{
	dup2(data->save_fd[0], STDIN_FILENO);
	close(data->save_fd[0]);
	dup2(data->save_fd[1], STDOUT_FILENO);
	close(data->save_fd[1]);
}

/**
 * @brief create a file for >.
 *
 * @param file	(char *)
 * @return (int) fd
 */
int	ft_create(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		perror(file);
	return (fd);
}

/**
 * @brief create a file for >>.
 *
 * @param file	(char *)
 * @return (int) fd
 */
int	ft_append(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		perror(file);
	return (fd);
}

/**
 * @brief read a file for <.
 *
 * @param file	(char *)
 * @return (int) fd
 */
int	ft_read(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror(file);
	return (fd);
}
