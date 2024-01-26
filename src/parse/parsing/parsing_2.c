/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:26 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/26 18:37:31 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *err)
{
	ft_putstr_fd("Syntax error near unexpected token ", 2);
	ft_putendl_fd(err, 2);
	g_exit_code = 2;
}

int	parse_pipes(t_cmd *cmd)
{
	while (cmd)
	{
		while (cmd->token)
		{
			if (cmd->token->type == BADCHAR || cmd->token->type == END)
				return (print_error(""), 0);
			if (cmd->token->type == D_BADCHAR || cmd->token->type == END)
				return (print_error(""), 0);
			if (cmd->token->type == PIPE || cmd->token->type == D_PIPE
				|| cmd->token->type == END)
				return (print_error("|"), 0);
			if (cmd->token->next)
				cmd->token = cmd->token->next;
			else
				break ;
		}
		cmd->token = tokenfirst(cmd->token);
		cmd = cmd->next;
	}
	return (1);
}

int	parse_redirections(t_cmd *cmd)
{
	while (cmd)
	{
		while (cmd->token)
		{
			if (token_is_redir(cmd->token))
			{
				if (!cmd->token->next)
				{
					if (!cmd->next)
						return (print_error("$"), 0);
					else
						return (print_error("|"), 0);
				}
				else if (!err_redir(cmd->token->next))
					return (print_error(cmd->token->content), 0);
			}
			if (cmd->token->next)
				cmd->token = cmd->token->next;
			else
				break ;
		}
		cmd->token = tokenfirst(cmd->token);
		cmd = cmd->next;
	}
	return (1);
}

int	token_is_redir(t_token *token)
{
	if (token->type == GREAT || token->type == D_GREAT || token->type == LESS
		|| token->type == D_LESS)
		return (1);
	return (0);
}

int	err_redir(t_token *token)
{
	if ((token->type == A_GREAT || token->type == A_DGREAT
			|| token->type == A_LESS || token->type == A_DLESS)
		&& ft_strlen(token->content))
		return (1);
	return (0);
}
