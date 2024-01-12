/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:15:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 22:11:25 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief check if the command is a builtin and execute it.
 *
 * @param args (char **) arguments
 * @param data (t_data *)
 *
 * @return int 1 if builtin, 0 if not
 */
int	builtin(char **args, t_data *data, int fd)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (echo(args, fd));
	else if (ft_strcmp(args[0], "cd") == 0)
		return (cd(args));
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (pwd(fd));
	else if (ft_strcmp(args[0], "export") == 0)
		return (export_builtin(args, fd, data->env_cpy));
	else if (ft_strcmp(args[0], "unset") == 0)
		return (unset(args, fd));
	else if (ft_strcmp(args[0], "env") == 0)
		return (env(data->env_cpy, fd));
	else if (ft_strcmp(args[0], "exit") == 0)
		return (exit_builtin(args, data));
	return (0);
}

/**
 * @brief check if the command is a builtin.
 *
 * @param str (char *) command
 * @return true if builtin, false if not
 */
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
