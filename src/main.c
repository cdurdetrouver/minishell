/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:50:02 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/17 02:01:05 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig		g_sig;

void	signal_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		exit(1);
	}
}

int	ft_heredoc(char *delimiter)
{
	int		fd[2];
	char	*line;

	pipe(fd);
	close(fd[1]);
	signal(SIGINT, signal_heredoc);
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, delimiter))
			break ;
		ft_putendl_fd(line, fd[0]);
		free(line);
	}
	if (line)
		free(line);
	signal(SIGINT, sig_handler);
	return (fd[0]);
}

/**
 * @brief parse the line to put it in t_cmd.
 *
 * @param data (t_data *) data of the program.
 * @return (int) should i execute the command, 0 if no, 1 if yes.
 */
// int	parsing_exe(t_data *data)
// {
// 	t_cmd	*cmd;

// 	// t_cmd	*cmd2;
// 	if (ft_strlen(data->line) == 0)
// 		return (data->cmd = NULL, 0);
// 	cmd = malloc(sizeof(t_cmd) * 1);
// 	cmd->argv = ft_split(data->line, ' ');
// 	cmd->cmd = ft_strdup(cmd->argv[0]);
// 	cmd->cmd_path = NULL;
// 	cmd->argc = 0;
// 	while (cmd->argv[cmd->argc])
// 		cmd->argc++;
// 	if (cmd->argc > 2 && ft_strcmp(cmd->argv[cmd->argc - 2], ">") == 0)
// 	{
// 		cmd->fd_out = open(cmd->argv[cmd->argc - 1],
// 				O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		cmd->argv[cmd->argc - 2] = NULL;
// 		cmd->argc -= 2;
// 	}
// 	else if (cmd->argc > 2 && ft_strcmp(cmd->argv[cmd->argc - 2], ">>") == 0)
// 	{
// 		cmd->fd_out = open(cmd->argv[cmd->argc - 1],
// 				O_WRONLY | O_CREAT | O_APPEND, 0644);
// 		cmd->argv[cmd->argc - 2] = NULL;
// 		cmd->argc -= 2;
// 	}
// 	else
// 		cmd->fd_out = 1;
// 	if (cmd->argc > 2 && ft_strcmp(cmd->argv[cmd->argc - 2], "<") == 0)
// 	{
// 		cmd->fd_in = open(cmd->argv[cmd->argc - 1], O_RDONLY);
// 		cmd->argv[cmd->argc - 2] = NULL;
// 		cmd->argc -= 2;
// 	}
// 	else if (cmd->argc > 2 && ft_strcmp(cmd->argv[cmd->argc - 2], "<<") == 0)
// 	{
// 		cmd->fd_in = ft_heredoc(cmd->argv[cmd->argc - 1]);
// 		printf("fd_in = %d\n", cmd->fd_in);
// 		cmd->argv[cmd->argc - 2] = NULL;
// 		cmd->argc -= 2;
// 	}
// 	else
// 		cmd->fd_in = 0;
// 	// free(data->line);
// 	// data->line = ft_strdup("wc -l");
// 	// cmd2 = malloc(sizeof(t_cmd) * 1);
// 	// cmd2->argv = ft_split(data->line, ' ');
// 	// cmd2->cmd = ft_strdup(cmd2->argv[0]);
// 	// cmd2->argc = 0;
// 	// cmd2->fd_in = -1;
// 	// cmd2->fd_out = open("test2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	// while (cmd2->argv[cmd2->argc])
// 	// 	cmd2->argc++;
// 	cmd->next = NULL; // cmd2
// 	cmd->prev = NULL;
// 	// cmd2->prev = cmd;
// 	// cmd2->next = NULL;
// 	data->cmd = cmd;
// 	return (1);
// }

int	parsing_exe(t_data *data)
{
	t_cmd	*cmd;
	t_cmd	*cmd2;
	t_cmd	*cmd3;

	cmd = malloc(sizeof(t_cmd) * 1);
	free(data->line);
	data->line = ft_strdup("ls");
	cmd->argv = ft_split(data->line, ' ');
	cmd->cmd = ft_strdup(cmd->argv[0]);
	cmd->fd_in = 0;
	cmd->fd_out = -1;
	free(data->line);
	cmd2 = malloc(sizeof(t_cmd) * 1);
	data->line = ft_strdup("sort");
	cmd2->argv = ft_split(data->line, ' ');
	cmd2->cmd = ft_strdup(cmd2->argv[0]);
	cmd2->fd_in = -1;
	cmd2->fd_out = open("test2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(data->line);
	cmd3 = malloc(sizeof(t_cmd) * 1);
	data->line = ft_strdup("head -n 2");
	cmd3->argv = ft_split(data->line, ' ');
	cmd3->cmd = ft_strdup(cmd3->argv[0]);
	cmd3->fd_in = -1;
	cmd3->fd_out = 1;
	cmd->next = cmd2;
	cmd->prev = NULL;
	cmd2->next = cmd3;
	cmd2->prev = cmd;
	cmd3->next = NULL;
	cmd3->prev = cmd2;
	data->cmd = cmd;
	return (1);
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
		if (parsing_exe(data))
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
