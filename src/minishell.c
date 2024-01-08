/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:12:56 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/08 20:51:42 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(void)
{
	char	*line;
	char	**args;

	signal(SIGINT, sigint_handler);
	line = readline("minishell$ ");
	while (ft_strcmp(line, "exit") != 0)
	{
		args = ft_split(line, ' ');
		execute(args);
		free(line);
		free(args);
		line = readline("minishell$ ");
	}
	free(line);
}
