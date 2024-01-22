/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:35:19 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 00:12:36 by gbazart          ###   ########.fr       */
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

t_env	*envlast(t_env *lst)
{
	t_env	*last;

	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	env_add_back(t_env **lst, char *key, char *value)
{
	t_env	*last;
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return ;
	env->key = ft_strdup(key);
	env->value = ft_strdup(value);
	env->next = NULL;
	if (!env->key || !env->value)
	{
		free(env);
		return ;
	}
	if (*lst == NULL)
		*lst = env;
	else
	{
		last = envlast(*lst);
		last->next = env;
	}
}

t_env	*create_env_list(char **envp)
{
	t_env	*head;
	char	**tmp;
	int		i;

	i = 0;
	head = NULL;
	while (envp[i])
	{
		tmp = ft_split(envp[i], '=');
		env_add_back(&head, tmp[0], tmp[1]);
		free_tab((void **)tmp);
		i++;
	}
	return (head);
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
	env_add_back(&env, key, value);
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
