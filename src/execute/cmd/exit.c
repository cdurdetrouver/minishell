/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:17:26 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/12 01:57:34 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * exit the program
 *
 * @param args (char **)
 * @param data (t_data *)
 * @return (int) 1 if it works, 0 if don't.
 */
int	exit_builtin(char **args, t_data *data)
{
	if (args[1] == NULL)
	{
		printf("exit\n");
		data->exit = true;
		g_exit = 1;
	}
	else if (args[1] && args[2] == NULL)
	{
		if (!ft_isnumeric(args[1]))
		{
			ft_putstr_fd("minishell: exit: ", 1);
			ft_putstr_fd(args[1], 1);
			ft_putstr_fd(": numeric argument required\n", 1);
			exit(255);
		}
		printf("exit\n");
		data->exit = true;
		g_exit = ft_atoi(args[1]);
	}
	else
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 1);
		return (0);
	}
	return (1);
}
