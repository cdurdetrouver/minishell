/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:59:06 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/14 17:18:26 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_unset_error(char **args)
{
	ft_putstr_fd("minishell: unset: `", 1);
	ft_putstr_fd(args[0], 1);
	ft_putstr_fd("': not a valid identifier\n", 1);
	g_sig.prompt_erreur = true;
	return (0);
}

/**
 * @brief print the unset error.
 *
 * @param args (char **)
 * @param fd (int)
 * @return (int) 1 if it works, 0 if don't.
 */
int	unset(char **args)
{
	int	i;

	i = 1;
	if (!args[1])
		return (print_unset_error(args));
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
			ft_putstr_fd("minishell: unset: `", 1);
		else
		{
			ft_putstr_fd(args[i], 1);
			ft_putstr_fd("': not a valid identifier\n", 1);
			g_sig.prompt_erreur = true;
		}
		i++;
	}
	return (1);
}
