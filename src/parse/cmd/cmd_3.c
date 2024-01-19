/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:21:42 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/18 19:00:56 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token_cmd(t_token *token, int i)
{
	t_token	*ret;
	t_token	*t;
	int		start;
	int		size;

	if (!token)
		return (NULL);
	if (i > tokensize(token) - 2)
		return (NULL);
	t = token;
	if (t->type == START)
		t = t->next;
	start = -1;
	while (++start < i)
		t = t->next;
	size = 0;
	while (t->type != PIPE && t->next)
	{
		t = t->next;
		size++;
	}
	ret = sub_token(token, start, size);
	if (!ret)
		return (NULL);
	return (ret);
}

void	arr_func(t_cmd *cmd, int *i, char **arr)
{
	if (cmd->token->type == ARG)
	{
		arr[*i] = ft_strdup(cmd->token->content);
		(*i)++;
	}
}

char	**char_arr(t_cmd *cmd)
{
	int		i;
	char	**arr;

	i = 0;
	while (cmd->token)
	{
		if (cmd->token->type == ARG)
			i++;
		if (!cmd->token->next)
			break ;
		cmd->token = cmd->token->next;
	}
	cmd->token = tokenfirst(cmd->token);
	arr = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (cmd->token)
	{
		arr_func(cmd, &i, arr);
		if (!cmd->token->next)
			break ;
		cmd->token = cmd->token->next;
	}
	cmd->token = tokenfirst(cmd->token);
	arr[i] = NULL;
	return (arr);
}

t_cmd	*create_cmd(t_token *token, int i)
{
	t_token	*st;
	t_token	*t;
	t_cmd	*cmd;
	char	*str;

	if (!token)
		return (NULL);
	st = token;
	t = create_token_cmd(st, i);
	if (!t)
		return (NULL);
	str = get_cmd_str(t);
	if (!str)
		return (NULL);
	cmd = cmdnew(str, t);
	free(str);
	if (!cmd)
		return (NULL);
	cmd->argv = char_arr(cmd);
	cmd->cmd_path = NULL;
	return (cmd);
}

t_cmd	*create_all_cmd(t_token *t)
{
	t_cmd	*cmd;
	t_cmd	*to_add;
	int		i;

	i = 0;
	cmd = create_cmd(t, i);
	i += tokensize(cmd->token) + 1;
	to_add = create_cmd(t, i);
	if (!to_add)
		return (cmd);
	i += tokensize(to_add->token) + 1;
	while (to_add)
	{
		cmdadd_back(&cmd, to_add);
		to_add = create_cmd(t, i);
		if (!to_add)
			return (cmd);
		i += tokensize(to_add->token) + 1;
	}
	return (cmd);
}
