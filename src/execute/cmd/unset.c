/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:59:06 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 00:14:06 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_unset(char *arg, t_env *env)
{
	if (ft_removeenv(&env, arg))
	{
		ft_putstr_fd("unset: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		g_sig.prompt_erreur = true;
	}
}

/**
 * @brief print the unset error.
 *
 * @param args (char **) args
 * @return (int) 1 if it works, 0 if don't.
 */
int	unset(char **args, t_env *env)
{
	int	i;

	i = 1;
	if (!args[1])
	{
		ft_putstr_fd("unset: not enough arguments\n", 2);
		g_sig.prompt_erreur = true;
		return (0);
	}
	else
	{
		while (args[i])
		{
			run_unset(args[i], env);
			i++;
		}
	}
	return (1);
}
