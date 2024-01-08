/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:28:15 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/07 20:31:12 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Print the arguments
 *
 * @param args t_cmd
 * @return 0 if works, 1 if not
 */
int	echo(t_cmd *args)
{
	int	i;

	i = 1;
	while (i < args->nbr_arg)
	{
		printf("%s ", args->args[i]);
		i++;
	}
	printf("\n");
	return (0);
}
