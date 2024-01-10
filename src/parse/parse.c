/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:29:40 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 15:42:56 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_data *data)
{
	int	i;

	if (ft_strlen(data->line) <= 0)
	{
		data->exec = false;
		return ;
	}
	data->start = malloc(sizeof(t_token));
	if (!data->start)
		return ;
	data->start->argv = ft_split(data->line, ' ');
	if (!data->start->argv)
		return ;
	i = 0;
	while (data->start->argv[i])
		i++;
	data->start->argc = i;
	data->start->next = NULL;
	data->exec = true;
}
