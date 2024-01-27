/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:59:06 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 01:03:57 by gbazart          ###   ########.fr       */
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
	return (1);
}
