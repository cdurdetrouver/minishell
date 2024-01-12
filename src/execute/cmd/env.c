/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:19:50 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 17:14:40 by gbazart          ###   ########.fr       */
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
int	env(char **env, int fd)
{
	while (*env)
	{
		ft_putstr_fd(*env, fd);
		ft_putchar_fd('\n', fd);
		env++;
	}
	return (1);
}
