/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:19:20 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/12 15:16:44 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * use cd on the path given.
 *
 * @param (char **) args
 * @return (int) 1 if it works, 0 if don't.
 */
int	cd(char **args)
{
	char	*path;

	if (args[1] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			ft_putstr_fd("cd: HOME not set\n", 1);
			g_sig.code_prompt = 1;
			return (0);
		}
	}
	else
		path = args[1];
	if (chdir(path) != 0)
	{
		ft_putstr_fd("cd: not a directory: ", 1);
		ft_putstr_fd(path, 1);
		ft_putchar_fd('\n', 1);
		g_sig.code_prompt = 1;
	}
	return (1);
}
