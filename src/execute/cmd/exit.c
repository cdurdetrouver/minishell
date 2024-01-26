/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:17:26 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/26 00:27:46 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	inf_to_llmin(char *num)
{
	char	ll_min[20];
	int		i;

	ft_strlcat(ll_min, "-9223372036854775808", 20);
	i = 1;
	if (num[0] != '-')
		return (false);
	if (ft_strlen(num) < 20)
		return (false);
	if (ft_strlen(num) > 20)
		return (true);
	while (num[i])
	{
		if ((num[i] - 48) > (ll_min[i] - 48))
			return (true);
		if ((num[i] - 48) < (ll_min[i] - 48))
			return (false);
		i++;
	}
	return (false);
}

bool	sup_to_llmax(char *num)
{
	char	ll_max[19];
	int		i;

	ft_strlcat(ll_max, "9223372036854775807", 19);
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
	else if (args[1] && args[2] == NULL)
	{
		if (!ft_isnumeric(args[1]) || sup_to_llmax(args[1]) == true
			|| inf_to_llmin(args[1]) == true)
		{
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(args[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit_setcode(data, 255);
		}
		else
			exit_setcode(data, ft_atoll(args[1]));
	}
	else
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		exit_setcode(data, 1);
	}
}
