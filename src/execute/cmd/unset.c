/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:59:06 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 01:31:55 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	}
	else
	{
		while (args[i++])
		{
			if (check_args(args[i]) == true)
				ft_removeenv(&env, args[i]);
			else
			{
				ft_putstr_fd("export: `", 2);
				ft_putstr_fd(args[i], 2);
				ft_putstr_fd("': not a valid identifier\n", 2);
				g_sig.prompt_erreur = true;
				return (1);
			}
		}
	}
	return (1);
}
