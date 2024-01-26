/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:06:36 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/24 20:16:26 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_plus(char *arg, t_env *env2)
{
	t_env	*tmp;
	char	*key;
	char	*value;

	tmp = env2;
	key = ft_substr(arg, 0, ft_strchr(arg, '+') - arg);
	value = ft_substr(arg, ft_strchr(arg, '+') - arg + 2, ft_strlen(arg));
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			tmp->value = ft_strjoin2(tmp->value, value);
			free(key);
			free(value);
			return ;
		}
		tmp = tmp->next;
	}
	ft_setenv(env2, key, value);
	free(key);
	free(value);
}

void	run_export(char *arg, t_env *env2)
{
	t_env	*tmp;
	char	*key;
	char	*value;

	if (ft_strchr(arg, '+'))
		return (ft_export_plus(arg, env2));
	tmp = env2;
	key = ft_substr(arg, 0, ft_strchr(arg, '=') - arg);
	value = ft_substr(arg, ft_strchr(arg, '=') - arg + 1, ft_strlen(arg));
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value;
			free(key);
			return ;
		}
		tmp = tmp->next;
	}
	ft_setenv(env2, key, value);
	free(value);
	free(key);
}

bool	check_args(char *arg)
{
	int	i;

	i = 0;
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (false);
	while (arg[++i] && arg[i] != '=' && arg[i] != '+')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (false);
	}
	if ((arg[i] == '+' && arg[i + 1] == '=') || arg[i] == '=' || !arg[i])
		return (true);
	return (false);
}

/**
 * @brief export the args given.
 *
 * @param args (char **)
 * @param fd (int)
 * @return (int) 1 if it works, 0 if don't.
 */
int	export_builtin(char **args, t_env *env2)
{
	if (!args[1])
		return (env(env2));
	else if (args[1] && !args[2])
	{
		if (check_args(args[1]) == true)
			run_export(args[1], env2);
		else
		{
			ft_putstr_fd("export: `", 2);
			ft_putstr_fd(args[1], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_exit_code = 1;
			return (1);
		}
	}
	return (1);
}
