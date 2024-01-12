/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:50:02 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/12 02:10:35 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			g_exit = 0;

/**
 * @brief main loop of the program.
 *
 * @param data (t_data *) data of the program.
 */
void	minishell(t_data *data)
{
	char	*prompt;

	data->start = NULL;
	using_history();
	while (data->exit == false)
	{
		signal(SIGINT, sigint_handler);
		prompt = getprompt();
		data->line = readline(prompt);
		free(prompt);
		if (data->line == NULL)
		{
			printf("exit\n");
			g_exit = 1;
			break ;
		}
		printf("line : %s\n", data->line);
		add_history(data->line);
		// parse(data);
		// if (data->exec == true)
		// 	execute(data);
		if (ft_strncmp(data->line, "exit", 4) == 0)
		{
			g_exit = 32;
			data->exit = true;
		}
		free_start(data);
	}
}

/**
 * @brief init the data of the program.
 *
 * @param data (t_data *) data of the program.
 * @param envp (char **) envp.
 */
static void	init_data(t_data *data, char **envp)
{
	data->exec = false;
	data->env_cpy = ft_ssdup(envp);
	data->exit = false;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init_data(&data, envp);
	minishell(&data);
	free_end(&data);
	return (g_exit);
}
