/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:12:25 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/07 20:31:04 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Check if the command is a builtin
 *
 * @param args t_cmd
 * @return true if builtin, false if not
 */
bool	is_builtin(t_cmd *args)
{
	if (ft_strcmp(args->name, "echo") == 0)
		return (true);
	else if (ft_strcmp(args->name, "cd") == 0)
		return (true);
	else if (ft_strcmp(args->name, "pwd") == 0)
		return (true);
	else if (ft_strcmp(args->name, "export") == 0)
		return (true);
	else if (ft_strcmp(args->name, "unset") == 0)
		return (true);
	else if (ft_strcmp(args->name, "env") == 0)
		return (true);
	return (false);
}
