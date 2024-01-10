/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:59:06 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 04:59:37 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * get the actual path
 *
 * @return int 1 if it works, 0 if don't.
 */
int	pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
	return (1);
}

/**
 * @brief export the args given.
 *
 * @param args (char **)
 * @return (int) 1 if it works, 0 if don't.
 */
int	export(char **args)
{
	int	i;

	i = 1;
	if (args[1] == NULL)
		printf("env\n");
	else
	{
		while (args[i])
		{
			if (ft_strchr(args[i], '='))
				printf("add to env %s", args[i]);
			else
				ft_putstr_fd("minishell: export: `", 1);
			ft_putstr_fd(args[i], 1);
			ft_putstr_fd("': not a valid identifier\n", 1);
			i++;
		}
	}
	return (1);
}

int	unset(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
			ft_putstr_fd("minishell: unset: `", 1);
		ft_putstr_fd(args[i], 1);
		ft_putstr_fd("': not a valid identifier\n", 1);
		i++;
	}
	return (1);
}
