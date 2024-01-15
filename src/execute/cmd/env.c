/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:19:50 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/14 17:17:15 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief print the env.
 *
 * @param env (char **) env
 * @param fd (int)
 * @return (int) 1 if it works, 0 if don't.
 */
int	env(char **env)
{
	while (*env)
	{
		ft_putstr_fd(*env, 1);
		ft_putchar_fd('\n', 1);
		env++;
	}
	return (1);
}
