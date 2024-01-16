/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:40:53 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/16 15:57:12 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
