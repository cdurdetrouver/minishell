/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:17:26 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/26 19:58:46 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MINDEOUF "-9223372036854775808"

bool	inf_to_llmin(char *num)
{
	int		i;

	i = 1;
	if (num[0] != '-')
		return (false);
	if (ft_strlen(num) < 20)
		return (false);
	if (ft_strlen(num) > 20)
		return (true);
	while (num[i])
	{
		if ((num[i] - 48) > (MINDEOUF[i] - 48))
			return (true);
		if ((num[i] - 48) < (MINDEOUF[i] - 48))
			return (false);
		i++;
	}
	return (false);
}

bool	sup_to_llmax(char *num)
{
	int		i;

	i = 0;
	if (num[0] == '-')
		return (false);
	if (ft_strlen(num) < 19)
		return (false);
	if (ft_strlen(num) > 19)
		return (true);
	while (num[i] && "9223372036854775807"[i])
	{
		if ((num[i] - 48) > ("9223372036854775807"[i] - 48))
			return (true);
		if ((num[i] - 48) < ("9223372036854775807"[i] - 48))
			return (false);
		i++;
	}
	if (num[i])
		return (true);
	return (false);
}

void	exit_setcode(t_data *data, long long code)
{
	data->exit = true;
	g_exit_code = code;
}

/**
 * exit the program
 *
 * @param args (char **)
 * @param data (t_data *)
 * @return (int) 1 if it works, 0 if don't.
 */
void	exit_builtin(char **args, t_data *data)
{
	if (args[1] == NULL)
		exit_setcode(data, 0);
	else if (!ft_isnumeric(args[1]) || sup_to_llmax(args[1]) == true
		|| inf_to_llmin(args[1]) == true)
	{
		ft_putendl_fd("exit", 2);
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit_setcode(data, 2);
	}
	else if (args[2])
		ft_putstr_fd("exit: too many arguments\n", 2);
	else
	{
		ft_putendl_fd("exit", 2);
		exit_setcode(data, ft_atoll(args[1]));
	}
}
