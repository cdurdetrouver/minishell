/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:47:53 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/07 20:08:37 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_sig
{
	int		sigint;
	int		sigquit;
	int		exit_status;
	pid_t	pid;
}			t_sig;

typedef struct s_cmd
{
	char	*name;
	char	**args;
	int		nbr_arg;
}			t_cmd;

typedef struct s_data
{
	char	**envp;
	char	*line;
	t_cmd	cmd;
	bool	end;
}			t_data;

void		minishell(t_data *data);

// CHECK
bool		is_builtin(t_cmd *args);

// EXECUTE
int			execute(t_cmd *cmd);

// PARSE
int			parse(t_data *data);

// SIGNAL
void		sigint_handler(int signum);

// FREE
void		free_all(char *line, t_cmd *args);

// CMD
int			echo(t_cmd *args);
int			cd(t_cmd *cmd);

#endif
