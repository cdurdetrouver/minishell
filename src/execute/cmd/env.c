/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:19:50 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/29 18:20:19 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief print the env.
 *
 * @param env (char **) env
 * @return (int) 1 if it works, 0 if don't.
 */
int	env(t_env *env, char **args)
{
	t_env	*tmp;

	if (args[1])
		return (g_exit_code = 1);
	tmp = env;
	while (tmp)
	{
		ft_putstr_fd(tmp->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(tmp->value, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	g_exit_code = 0;
	return (1);
}
