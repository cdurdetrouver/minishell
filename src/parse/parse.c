/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:32:08 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/07 20:30:51 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	parse_line(char *line)
{
	t_cmd	args;
	int		i;

	i = 0;
	args.name = ft_strtrim(line, " ");
	args.args = ft_split(line, ' ');
	while (args.args[i++])
		args.nbr_arg++;
	return (args);
}

/**
 * @brief read a line and parse it
 *
 * @param data t_data
 * @return 0 if works, 1 if not
 */
int	parse(t_data *data)
{
	char	*line;
	t_cmd	cmd;

	line = readline("minishell$ ");
	if (line == NULL)
	{
		data->end = true;
		return (1);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (1);
	}
	cmd = parse_line(line);
	if (cmd.name == NULL)
	{
		free(line);
		return (1);
	}
	printf("cmd.name = %s\n", cmd.name);
	printf("cmd.args = %s\n", cmd.args[0]);
	printf("cmd.nbr_arg = %d\n", cmd.nbr_arg);
	minishell(data);
	free_all(line, &cmd);
	return (0);
}
