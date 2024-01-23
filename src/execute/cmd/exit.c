/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:17:26 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 16:09:33 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	inf_to_llmin(char *num)
{
	char	ll_max[20] = "-9223372036854775808";
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
		if ((num[i] - 48) > (ll_max[i] - 48))
			return (true);
		if ((num[i] - 48) < (ll_max[i] - 48))
			return (false);
		i++;
	}
	return (false);
}

bool	sup_to_llmax(char *num)
{
	char	ll_max[19] = "9223372036854775807";
	int		i;

	i = 0;
	if (num[0] == '-')
		return (false);
	if (ft_strlen(num) < 19)
		return (false);
	if (ft_strlen(num) > 19)
		return (true);
	while (num[i] && ll_max[i])
	{
		if ((num[i] - 48) > (ll_max[i] - 48))
			return (true);
		if ((num[i] - 48) < (ll_max[i] - 48))
			return (false);
		i++;
	}
	if (num[i])
		return (true);
	return (false);
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
	{
		data->exit = true;
		g_sig.exit_code = 0;
	}
	else if (args[1] && args[2] == NULL)
	{
		if (!ft_isnumeric(args[1]) || sup_to_llmax(args[1]) == true
			|| inf_to_llmin(args[1]) == true)
		{
			ft_putstr_fd("exit: ", 1);
			ft_putstr_fd(args[1], 1);
			ft_putstr_fd(": numeric argument required\n", 2);
			data->exit = true;
			g_sig.exit_code = 1;
		}
		else
		{
			data->exit = true;
			g_sig.exit_code = ft_atoll(args[1]);
		}
	}
	else
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		data->exit = true;
		g_sig.exit_code = 1;
	}
}
