/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:50:02 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/19 14:25:29 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig		g_sig;

/**
 * @brief parse the line to put it in t_cmd.
 *
 * @param data (t_data *) data of the program.
 * @return (int) should i execute the command, 0 if no, 1 if yes.
 */
int	parsing_exe(t_data *data)
{
	char	*s;

	if (!closed_quotes(data->line))
		return (ft_printf("quote error\n"), 0);
	s = new_str(data->line);
	data->t = init_tokens(s);
	// print_token(data->t);
	free(s);
	data->cmd = create_all_cmd(data->t);
	ft_assign_redirection_types(data->cmd);
	tokenclear(data->t);
	return (0);
}

/**
 * @brief main loop of the program.
 *
 * @param data (t_data *) data of the program.
 */
void	minishell(t_data *data)
{
	using_history();
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGTSTP, SIG_IGN);
	while (data->exit == false)
	{
		data->line = readline(getprompt());
		g_sig.prompt_erreur = false;
		if (data->line == NULL)
		{
			g_sig.exit_code = 0;
			break ;
		}
		add_history(data->line);
		if (!parsing_exe(data))
		{
			print_cmd_argv(data->cmd);
			execute(data);
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
	data->env_cpy = ft_ssdup(envp);
	data->exit = false;
	data->cmd = NULL;
	data->line = NULL;
	g_sig.exit_code = 0;
	g_sig.prompt_erreur = false;
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
	init_data(&data, envp);
	minishell(&data);
	free_end(&data);
	return (printf("exit\n"), g_sig.exit_code);
}
