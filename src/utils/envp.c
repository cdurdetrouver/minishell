/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:35:19 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 01:13:21 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief duplicate a string array.
 *
 * @param ss (char **) string array to duplicate.
 * @return (char **) don't forget to free it.
 */
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

t_env	*env_new(char *en)
{
	t_env	*node;
	char	**dptr;

	dptr = ft_split(en, '=');
	node = malloc(sizeof(t_env));
	if (!node)
	{
		free_tab((void **)dptr);
		return (NULL);
	}
	node->key = ft_strdup(dptr[0]);
	if (ft_strchr(en, '=') != NULL)
		node->value = ft_strdup(ft_strchr(en, '=') + 1);
	else
		node->value = ft_strdup("");
	free_tab((void **)dptr);
	node->next = NULL;
	return (node);
}

t_env	*envlast(t_env *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

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

void	ft_setenv(t_env *env, char *key, char *value)
{
	t_env	*tmp;
	char	*tmp2;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	tmp2 = ft_strjoin(key, "=");
	tmp2 = ft_strjoin2(tmp2, value);
	tmp = env_new(tmp2);
	free(tmp2);
	env_add_back(&env, tmp);
}

int	ft_removeenv(t_env **env, char *key)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = *env;
	prev = NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			if (prev)
				prev->next = tmp->next;
			else
				*env = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return (0);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}

char	**env_to_tab(t_env *env)
{
	char	**tab;
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (env)
	{
		tab[i] = ft_strjoin(env->key, "=");
		tab[i] = ft_strjoin2(tab[i], env->value);
		i++;
		env = env->next;
	}
	tab[i] = NULL;
	return (tab);
}
