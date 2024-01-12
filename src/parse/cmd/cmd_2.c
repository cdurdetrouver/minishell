/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:32:58 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/11 15:52:27 by gbazart          ###   ########.fr       */
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
	while (token->next && !token->content)
		token = token->next;
	if (token)
	{
		str = ft_strdup(token->content);
		token = token->next;
	}
	while (token)
	{
		if (token->content && token->type != END)
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
	ret = tokennew(ft_strdup(token->content), token->type);
	while (i++ < size + start && token->next)
	{
		token = token->next;
		ret->next = tokennew(ft_strdup(token->content), token->type);
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
		printf("in %d out %d\n", cmd->fd_in, cmd->fd_out);
		cmd = cmd->next;
	}
}
