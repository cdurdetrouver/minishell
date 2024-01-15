/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:18:48 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/14 17:17:06 by gbazart          ###   ########.fr       */
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
int	echo(char **args)
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
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!n)
		ft_putstr_fd("\n", 1);
	return (1);
}
