/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:50:02 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/26 19:54:58 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			g_exit_code;

/**
 * @brief parse the line to put it in t_cmd.
 *
 * @param data (t_data *) data of the program.
 * @return (int) should i execute the command, 0 if no, 1 if yes.
 */
int	parsing_exe(t_data *data)
{
	char	*s;

	if (!data->line || !*data->line || ft_is_space_str(data->line))
		return (1);
	if (!closed_quotes(data->line))
		return (ft_printf("Quote error\n"), 1);
	s = new_str(data->line, data->env);
	if (!s)
		return (1);
	data->t = init_tokens(s);
	free(s);
	data->cmd = create_all_cmd(data->t);
	if (!parse(data->cmd))
	{
		tokenclear(data->t);
		return (1);
	}
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
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	while (data->exit == false)
	{
		data->line = readline(getprompt(data));
		if (data->line == NULL)
		{
			ft_putendl_fd("exit", 2);
			g_exit_code = 0;
			break ;
		}
		add_history(data->line);
		if (!parsing_exe(data))
			execute(data);
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
	data->env = NULL;
	create_env_list(&data->env, envp);
	data->exit = false;
	data->cmd = NULL;
	data->line = NULL;
	g_exit_code = 0;
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
	return (g_exit_code);
}
