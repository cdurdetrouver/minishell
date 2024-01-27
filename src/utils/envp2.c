/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 00:35:50 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 00:25:41 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief create a new env node.
 *
 * @param en (char *) env
 * @return (t_env *) new node
 */
t_env	*env_new(char *en)
{
	t_env	*node;
	char	**dptr;

	dptr = ft_split(en, '=');
	if (!dptr)
		return (NULL);
	node = malloc(sizeof(t_env));
	if (!node)
	{
		free_tab((void **)dptr);
		return (NULL);
	}
	node->key = ft_strdup(dptr[0]);
	if (!node->key)
		return (NULL);
	if (ft_strchr(en, '=') != NULL)
		node->value = ft_strdup(ft_strchr(en, '=') + 1);
	else
		node->value = ft_strdup("");
	if (!node->value)
		return (NULL);
	free_tab((void **)dptr);
	node->next = NULL;
	return (node);
}

/**
 * @brief get the last node of the env list.
 *
 * @param head (t_env *) head of the env list
 * @return (t_env *) last node
 */
t_env	*envlast(t_env *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

/**
 * @brief add a node at the end of the env list.
 *
 * @param head (t_env **) head of the env list
 * @param new_list (t_env *) node to add
 */
void	env_add_back(t_env **head, t_env *new_list)
{
	t_env	*node;

	if (*head == NULL)
	{
		*head = new_list;
		(*head)->next = NULL;
		return ;
	}
	node = envlast(*head);
	node->next = new_list;
	new_list->next = NULL;
}

/**
 * @brief create the env list.
 *
 * @param head (t_env **) head of the env list
 * @param envp (char **) envp
 */
void	create_env_list(t_env **head, char **envp)
{
	int		i;
	t_env	*new_list;

	i = 0;
	while (envp[i])
	{
		new_list = env_new(envp[i]);
		env_add_back(head, new_list);
		i++;
	}
}

/**
 * @brief get the env value of the key.
 *
 * @param env (t_env *) env list
 * @param key (char *) key
 * @return (char *) value
 */
char	*ft_getenv(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
