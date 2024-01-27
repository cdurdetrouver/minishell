/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:44:58 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/26 23:59:52 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief print the error message.
 *
 * @param limiter (char *)
 */
void	print_heredoc_error(char *limiter)
{
	ft_putstr_fd("minishell: warning: here-document delimited ", 2);
	ft_putstr_fd("by end-of-file (wanted `", 2);
	ft_putstr_fd(limiter, 2);
	ft_putendl_fd("')", 2);
}

/**
 * @brief signal handler for heredoc.
 *
 * @param sig (int) signal.
 */
void	sig_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		close(0);
		g_exit_code = 1;
	}
}

/**
 * @brief read and write lines in the file.
 *
 * @param fd (int) fd of the file.
 * @param limiter (char *)
 */
void	read_and_write_lines(int fd, char *limiter)
{
	char	*line;

	signal(SIGINT, sig_heredoc);
	line = readline("> ");
	while (line != NULL)
	{
		if (ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
		line = readline("> ");
		if (!line && g_exit_code == 0)
			print_heredoc_error(limiter);
	}
	signal(SIGINT, sig_handler);
}

/**
 * @brief create a file with the heredoc and fill it.
 *
 * @param limiter (char *)
 * @return (int) fd of the file.
 */
int	ft_heredoc(char *limiter)
{
	static char	filename[20] = {"/tmp/heredoc_file"};
	int			fd;
	int			old_exit_code;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open failed");
		return (fd);
	}
	old_exit_code = g_exit_code;
	g_exit_code = 0;
	read_and_write_lines(fd, limiter);
	close(fd);
	if (g_exit_code == 1)
	{
		g_exit_code = old_exit_code;
		return (-1);
	}
	g_exit_code = old_exit_code;
	fd = open(filename, O_RDWR);
	if (fd == -1)
		perror("open failed");
	return (fd);
}
