/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:32:58 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/23 14:18:56 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmdlast(t_cmd *lst)
{
	if (!lst || !lst->next)
		return (lst);
	lst = lst->next;
	return (cmdlast(lst));
}

t_cmd	*cmdfirst(t_cmd *lst)
{
	if (!lst || !lst->prev)
		return (lst);
	lst = lst->prev;
	return (cmdfirst(lst));
}

char	*get_cmd_str(t_token *token)
{
	char	*str;
	char	*tmp;

	if (!token)
		return (NULL);
	str = ft_strdup("");
	while (token->next && !token->content)
		token = token->next;
	while (token)
	{
		if (token->content)
		{
			tmp = ft_strjoin(str, token->content);
			free(str);
			str = ft_strdup(tmp);
			free(tmp);
		}
		token = token->next;
	}
	return (str);
}

t_token	*sub_token(t_token *token, int start, int size)
{
	int		i;
	t_token	*ret;

	if (start > tokensize(token))
		return (NULL);
	i = -1;
	while (++i < start + 1 && token->next)
		token = token->next;
	ret = tokennew(token->content, token->type);
	while (i++ < size + start && token->next)
	{
		token = token->next;
		ret->next = tokennew(token->content, token->type);
		ret->next->prev = ret;
		ret = ret->next;
	}
	ret->next = NULL;
	return (tokenfirst(ret));
}

void	print_cmd(t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd)
	{
		printf("Command %d :\n\t Content %s\n\tToken size : %d\n\n", i++,
			cmd->cmd, tokensize(cmd->token));
		//printf("in %d out %d\n", cmd->file_in, cmd->file_out);
		cmd = cmd->next;
	}
}

void print_cmd_argv(t_cmd *cmd) {
	int i;

	i = 1;
	while (cmd) {
		printf("Command %d:\n", i++);
		if (cmd->argv) {
			int j = 0;
			while (cmd->argv[j]) {
				//printf("cmd = %s\n", cmd->cmd);
				printf("\tArgument %d: %s\n", j + 1, cmd->argv[j]);
				j++;
			}
		//printf("\tin %d out %d\n", cmd->file_in, cmd->file_out);
		printf("File In Type: %d \tFile In File: %s \n", cmd->file_in.type, cmd->file_in.file);
		printf("File Out Type: %d \tFile Out File: %s \n", cmd->file_out.type, cmd->file_out.file);
		} else {
			printf("\tNo arguments\n");
		}
		cmd = cmd->next;
	}
}


