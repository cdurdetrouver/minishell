/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:15:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 01:38:24 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief check if the command is a builtin
 *
 * @param args char ** of arguments
 * @return int 1 if builtin, 0 if not
 */
int	builtin(char **args)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (echo(args));
	else if (ft_strcmp(args[0], "cd") == 0)
		return (cd(args));
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (pwd());
	else if (ft_strcmp(args[0], "export") == 0)
		return (export(args));
	else if (ft_strcmp(args[0], "unset") == 0)
		return (unset(args));
	else if (ft_strcmp(args[0], "env") == 0)
		return (env());
	else if (ft_strcmp(args[0], "exit") == 0)
		return (exit_builtin(args));
	return (0);
}

bool	is_builtin(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (true);
	else if (ft_strcmp(str, "cd") == 0)
		return (true);
	else if (ft_strcmp(str, "pwd") == 0)
		return (true);
	else if (ft_strcmp(str, "export") == 0)
		return (true);
	else if (ft_strcmp(str, "unset") == 0)
		return (true);
	else if (ft_strcmp(str, "env") == 0)
		return (true);
	else if (ft_strcmp(str, "exit") == 0)
		return (true);
	return (false);
}
