/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:47:53 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 04:52:01 by gbazart          ###   ########.fr       */
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
# include <sys/wait.h>
# include <unistd.h>

typedef enum e_operator
{
	NONE,
	GREAT,
	LESS,
	GREATGREAT,
	LESSLESS,
	PIPE,
}					t_operator;

typedef struct s_token
{
	int				argc;
	char			**argv;
	t_operator		operator;
	struct s_token	*next;
}					t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	t_token			*start;
	t_env			*env;
	char			*line;
	bool			exit;
	bool			exec;
}					t_data;

void				minishell(t_data *data);
bool				is_builtin(char *s);

// EXECUTE
void				execute(t_data *data);
int					builtin(char **args);
int					echo(char **args);
int					cd(char **args);
int					pwd(void);
int					export(char **args);
int					unset(char **args);
int					env(void);
int					exit_builtin(char **args);
void				sigint_handler(int signum);

// PARSE
void				parse(t_data *data);

// FREE
void				free_start(t_token *start);
void				free_env(t_env *head);
void				free_tab(char **tab);
char				*ft_strjoin2(char *s1, char *s2);

// UTILS
t_env				*ft_lstenv(char **envp);
void				print_env(t_env *head);

#endif
