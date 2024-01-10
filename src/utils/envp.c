/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:35:19 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 15:53:52 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_ssdup(char **ss)
{
	char	**new;
	int		i;

	i = 0;
	while (ss[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (ss[i])
	{
		new[i] = ft_strdup(ss[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

char	*ft_getenv(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	ft_lstadd_back_env(t_env *head, t_env *new)
{
	t_env	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static t_env	*ft_lstnew_env(char *str)
{
	t_env	*new;
	char	**ss;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	ss = ft_split(str, '=');
	if (!ss)
		return (NULL);
	if (!ss[0])
		new->key = ft_strdup("");
	else
		new->key = ft_strdup(ss[0]);
	if (!ss[1])
		new->value = ft_strdup("");
	else
		new->value = ft_strdup(ss[1]);
	free_tab(ss);
	new->next = NULL;
	return (new);
}

t_env	*ft_lstenv(char **envp)
{
	t_env	*head;
	int		i;

	head = ft_lstnew_env(envp[0]);
	i = 1;
	while (envp[i])
	{
		ft_lstadd_back_env(head, ft_lstnew_env(envp[i]));
		i++;
	}
	return (head);
}
