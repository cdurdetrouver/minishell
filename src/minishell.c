/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:12:56 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/04 15:37:42 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell(void)
{
	char	*line;
	char	**args;

	signal(SIGINT, sigint_handler);
	line = readline("minishell$ ");
	while (ft_strcmp(line, "exit") != 0)
	{
		args = ft_split(line, ' ');
		printf("%s\n", args[0]);
		free(line);
		free(args);
		line = readline("minishell$ ");
	}
	free(line);
}
