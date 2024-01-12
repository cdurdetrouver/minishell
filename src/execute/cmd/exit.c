/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:17:26 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/12 15:18:57 by gbazart          ###   ########.fr       */
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
		g_sig.exit_code = 1;
	}
	else if (args[1] && args[2] == NULL)
	{
		if (!ft_isnumeric(args[1]))
		{
			ft_putstr_fd("minishell: exit: ", 1);
			ft_putstr_fd(args[1], 1);
			ft_putstr_fd(": numeric argument required\n", 1);
			g_sig.code_prompt = 1;
		}
		printf("exit\n");
		data->exit = true;
		g_sig.exit_code = ft_atoi(args[1]);
	}
	else
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 1);
		g_sig.code_prompt = 1;
		return (0);
	}
	return (1);
}
