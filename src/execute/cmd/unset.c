/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:59:06 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 15:47:13 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief print the unset error.
 *
 * @param args (char **) args
 * @return (int) 1 if it works, 0 if don't.
 */
int	unset(char **args, t_env *env)
{
	int	i;

	i = 0;
	while (args[++i])
		ft_removeenv(&env, args[i]);
	return (1);
}
