/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:50:02 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/12 13:27:23 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig		g_sig;

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
		g_sig.code_prompt = 0;
		if (data->line == NULL)
		{
			printf("exit\n");
			free(prompt);
			g_sig.exit_code = 1;
			break ;
		}
		printf("line : %s\n", data->line);
		add_history(data->line);
		parse(data);
		if (data->exec == true)
			execute(data);
		if (ft_strncmp(data->line, "exit", 4) == 0)
		{
			g_sig.exit_code = 32;
			data->exit = true;
		}
		free_start(data, prompt);
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

/**
 * @brief main function of the program
 *
 * @param argc (int) number of string in argv
 * @param argv (char **) parameter put in the program
 * @param envp (char **) environment variable
 * @return (int) exit code.
 */
int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	g_sig.code_prompt = 0;
	init_data(&data, envp);
	minishell(&data);
	free_end(&data);
	return (g_sig.exit_code);
}
