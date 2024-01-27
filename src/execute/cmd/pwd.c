/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:06:46 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/28 00:39:13 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief print the pwd.
 *
 * @param fd (int) fd
 * @return (int) 1 if it works, 0 if don't.
 */
int	pwd(t_data *data)
{
	if (!ft_getenv(data->env, "PWD"))
	{
		ft_putstr_fd("pwd: No such file or directory\n", 2);
		g_exit_code = 1;
		return (0);
	}
	ft_putstr_fd(ft_getenv(data->env, "PWD"), 1);
	ft_putstr_fd("\n", 1);
	g_exit_code = 0;
	return (1);
}
