/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:18:48 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 17:14:43 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * print the args given.
 *
 * @param args (char **) args
 * @param fd (int)
 * @return (int) 1 if it works, 0 if don't.
 */
int	echo(char **args, int fd)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		n = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], fd);
		if (args[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (!n)
		ft_putstr_fd("\n", fd);
	return (1);
}
