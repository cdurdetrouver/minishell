/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:06:46 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 17:09:30 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief print the pwd.
 *
 * @param fd (int) fd
 * @return (int) 1 if it works, 0 if don't.
 */
int	pwd(int fd)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		ft_putstr_fd("pwd: error retrieving current directory: ", 1);
		ft_putstr_fd("getcwd: cannot access parent directories: ", 1);
		ft_putstr_fd("No such file or directory\n", 1);
		return (0);
	}
	ft_putstr_fd(path, fd);
	ft_putstr_fd("\n", fd);
	free(path);
	return (1);
}
