/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:47:53 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 16:51:33 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "parse.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

extern int g_sigint;

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
    char **envp;
	char			*line;
	bool			exit;
	bool			exec;
}					t_data;


# include "execute.h"

void				minishell(t_data *data);
bool				is_builtin(char *s);

// EXECUTE
void				execute(t_data *data);

// PARSE
void				parse(t_data *data);

// FREE
void				free_start(t_token *start);
void				free_env(t_env *head);
void				free_tab(char **tab);

// UTILS
t_env				*ft_lstenv(char **envp);
void				print_env(t_env *head);
char	            **ft_ssdup(char **ss);
char	*joinss(char **ss);
void	print_tab(char **tab);
char	*ft_getenv(t_env *env, char *key);
char	*ft_strjoin2(char *s1, char *s2);

#endif