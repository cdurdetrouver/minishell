/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:47:53 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/05 18:20:59 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char	*name;
	char	**arg;
}			t_cmd;

void		minishell(void);
void		execute(char **args);
int			builtin(char **args);

// CMD
int			echo(char **args);
int			cd(char **args);
int			pwd(void);
int			export(char **args);
int			unset(char **args);
int			env(void);
int			exit_builtin(char **args);

// SIGNAL
void		sigint_handler(int signum);

// FREE
void		free_all(char *line, t_cmd *args);

#endif