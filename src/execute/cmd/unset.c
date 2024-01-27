/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:59:06 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 15:35:23 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief print the unset error.
 *
 * @param args (char **) args
 * @return (int) 1 if it works, 0 if don't.
 */
int	unset(char **args, t_data *data)
{
	int	i;

	i = 0;
	while (args[++i])
		ft_removeenv(&data->env, args[i]);
	g_exit_code = 0;
	return (1);
}
