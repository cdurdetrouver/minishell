/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:06:46 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 18:32:02 by hlamnaou         ###   ########.fr       */
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
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		if (ft_getenv("PWD", data->env))
			path = ft_strdup(ft_getenv("PWD", data->env));
		else
			path = ft_strdup("");
		ft_putstr_fd("pwd: No such file or directory\n", 2);
		g_exit_code = 1;
		return (0);
	}
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
	g_exit_code = 0;
	return (1);
}
