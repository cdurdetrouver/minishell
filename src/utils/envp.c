/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:35:19 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 01:02:47 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief set the value of the key.
 *
 * @param env (t_env *) env
 * @param key (char *) key
 * @param value (char *) value
 */
void	ft_setenv(t_env **env, char *key, char *value)
{
	t_env	*tmp;
	char	*tmp2;

	tmp = *env;
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
	env_add_back(env, tmp);
}

/**
 * @brief remove the key from the env.
 *
 * @param env (t_env **) env
 * @param key (char *) key
 * @return (int) 0 if it works, 1 if don't.
 */
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

/**
 * @brief convert env to string array.
 *
 * @param env (t_env *) env
 * @return (char **) don't forget to free it.
 */
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
