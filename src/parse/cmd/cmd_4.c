/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:49:46 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/18 19:53:58 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	output(t_cmd *cmd)
// {
// 	int	fd_out;

// 	fd_out = -1;
// 	if (cmd->token->type == A_GREAT)
// 		fd_out = open(cmd->token->content, O_WRONLY | O_CREAT | O_TRUNC, 0666);
// 	else if (cmd->token->type == A_DGREAT)
// 		fd_out = open(cmd->token->content, O_WRONLY | O_CREAT | O_APPEND, 0666);
// 	if (fd_out < 0)
// 	{
// 		if (cmd->fd_out > 0)
// 			close(cmd->fd_out);
// 		return (ft_printf("fd error\n"));
// 	}
// 	if (cmd->fd_out > 0)
// 		close(cmd->fd_out);
// 	cmd->fd_out = fd_out;
// 	return (0);
// }

// int	input(t_cmd *cmd)
// {
// 	int	fd_in;

// 	fd_in = open(cmd->token->content, O_RDONLY);
// 	if (fd_in < 0)
// 		return (ft_printf("%s: No such file or directory\n",
// 				cmd->token->content));
// 	cmd->fd_in = fd_in;
// 	return (0);
// }
