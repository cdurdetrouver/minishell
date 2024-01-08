/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:12:56 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/07 20:04:21 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Execute the command
 *
 * @param cmd t_cmd
 */
void	minishell(t_data *data)
{
	signal(SIGINT, sigint_handler);
	if (is_builtin(&data->cmd))
		execute(&data->cmd);
	else
		printf("is builtin\n");
}
