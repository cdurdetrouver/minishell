/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:06:36 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/14 17:17:29 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief export the args given.
 *
 * @param args (char **)
 * @param fd (int)
 * @return (int) 1 if it works, 0 if don't.
 */
int	export_builtin(char **args, char **env_cpy)
{
	int	i;

	i = 1;
	if (!args[1])
		return (env(env_cpy));
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			if (ft_strchr(args[i], '+'))
				printf("export +\n");
			else
				printf("export =\n");
		}
		else
			ft_putstr_fd("export: not a valid identifier\n", 1);
		i++;
	}
	return (1);
}
