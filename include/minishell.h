/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:47:53 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/12 01:59:17 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <aio.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

extern int			g_exit;

typedef enum e_type
{
	NONE,
	ARG,
	GREAT,
	D_GREAT,
	LESS,
	D_LESS,
	A_LESS,
	A_DLESS,
	A_GREAT,
	A_DGREAT,
	PIPE,
	D_PIPE,
	START,
	END
}					t_type;

typedef struct s_token
{
	char			*content;
	t_type			type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_cmd
{
	int				argc;
	char			*cmd;
	char			**cmd_arg;
	int				fd_in;
	int				fd_out;
	t_token			*token;
	int				status;
	pid_t			pid;
	pid_t			pid_one;
	char			*cmd_path;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_exp
{
	char			*var;
	int				index;
	struct s_exp	*next;
}					t_exp;

typedef struct s_data
{
	t_token			*start;
	t_cmd			*cmd;
	char			**env_cpy;
	char			*line;
	bool			exit;
	bool			exec;
}					t_data;

// MAIN
void				minishell(t_data *data);
bool				is_builtin(char *s);

// EXPAND
t_exp				*expnew(char *content, int index);
t_exp				*explast(t_exp *exp);
void				expclear(t_exp *exp);
void				expadd_back(t_exp **lst, t_exp *new);
int					get_var_len(char *str);
int					env_char(char c);
int					memory_needed(char *str, t_exp *exp);
t_exp				*init_expand(char *s);
void				print_expand(t_exp *exp);
char				*expand(char *s);
void				expand_func_3(char *s, int *i);

// STR
char				*remove_quotes(char *str);
int					skip_and_copy(char *str, char *ret, int *i, int *j);
void				skip_spaces(char *str, int *i, int *j);
char				*remove_spaces(char *s);
int					spaces_to_add(char *s);
int					space_func(char *s, char *ret, int *i, int *j);
char				*add_space(char *s);
char				*new_str(char *str);
int					is_space(char c);

// TOKEN
void				tokenadd_back(t_token **lst, t_token *new);
int					tokensize(t_token *lst);
t_token				*tokennew(char *content, t_type type);
void				tokenclear(t_token *lst);
t_token				*tokenlast(t_token *lst);
t_token				*tokenfirst(t_token *lst);
void				print_token(t_token *token);
t_type				get_type(char *s);
t_token				*init_tokens(char *s);
int					is_sep(t_type type);
void				give_types(t_token *t);
int					type_is_sep(t_type type);
void				quote(t_token *t);

// CMD
void				cmdadd_back(t_cmd **lst, t_cmd *new);
int					cmdsize(t_cmd *lst);
t_cmd				*cmdnew(char *content, t_token *token);
void				cmdclear(t_cmd *lst);
t_cmd				*cmdlast(t_cmd *lst);
t_cmd				*cmdfirst(t_cmd *lst);
char				*get_cmd_str(t_token *token);
t_token				*sub_token(t_token *token, int start, int size);
void				print_cmd(t_cmd *cmd);
t_token				*create_token_cmd(t_token *token, int i);
void				arr_func(t_cmd *cmd, int *i, char **arr);
char				**char_arr(t_cmd *cmd);
t_cmd				*create_cmd(t_token *token, int i);
t_cmd				*create_all_cmd(t_token *t);
int					output(t_cmd *cmd);
int					input(t_cmd *cmd);
int					give_fd(t_cmd *cmd);

// PARSING
int					skip_quotes(char const *s, int *i);
int					is_cmd(char *cmd);
int					closed_quotes(char *s);
int					max(int a, int b);
void				print_error(char *err);
int					parse_pipes(t_cmd *cmd);
int					parse_redirections(t_cmd *cmd);
int					token_is_redir(t_token *token);
int					err_redir(t_token *token);
int					parse(t_cmd *cmd);

// BUILTIN
bool				is_builtin(char *s);
int					builtin(char **args, t_data *data, int fd);
int					cd(char **args);
int					echo(char **args, int fd);
int					env(char **env, int fd);
int					exit_builtin(char **args, t_data *data);
int					export_builtin(char **args, int fd, char **env);
int					pwd(int fd);
int					unset(char **args, int fd);

// EXECUTE

// SIGNAL
void				sigint_handler(int signum);

// FREE
void				free_start(t_data *data);
void				free_end(t_data *data);
void				free_tab(void **tab);

// UTILS
char				**ft_ssdup(char **ss);
char				*ft_strjoin2(char *s1, char *s2);
char				*getprompt(void);

// DEBUG
void				print_tab(char **tab);

#endif
