/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:49:46 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/23 12:06:38 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_assign_redirection_types(t_cmd *cmd)
{
	while (cmd)
	{
		t_token *t = cmd->token;
		while (t->next)
		{
			if (t->content)
			{
				t_type type = get_type(t->content);
				//printf ("type: %d\n", type);
				if (type == GREAT || type == D_GREAT)
				{
					cmd->file_out.type = (type == GREAT) ? R_GREAT : RD_GREAT;
					cmd->file_out.file = t->next->content;
				}
				else if (type == LESS || type == D_LESS)
				{
					cmd->file_in.type = (type == LESS) ? R_LESS : RD_LESS;
					cmd->file_in.file = t->next->content;
				}
			}
			t = t->next;
		}
		cmd = cmd->next;
	}
}
