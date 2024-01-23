/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:00:46 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 02:51:04 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_save_fd(t_data *data)
{
	data->save_fd[0] = dup(STDIN_FILENO);
	data->save_fd[1] = dup(STDOUT_FILENO);
}

void	ft_restore_fd(t_data *data)
{
	dup2(data->save_fd[0], STDIN_FILENO);
	close(data->save_fd[0]);
	dup2(data->save_fd[1], STDOUT_FILENO);
	close(data->save_fd[1]);
}
