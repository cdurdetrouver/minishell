/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:57:13 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/11 15:32:32 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse(t_cmd *cmd)
{
	if (cmdsize(cmd) == 1 && tokensize(cmd->token) == 1
		&& cmd->token->type == 13)
		return (1);
	if (!parse_pipes(cmd))
		return (0);
	if (!parse_redirections(cmd))
		return (0);
	return (1);
}
