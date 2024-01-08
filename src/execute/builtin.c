/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:15:21 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/08 20:52:06 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
