/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:47:53 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/29 13:03:53 by hlamnaou         ###   ########.fr       */
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

# define MIN_LL "-9223372036854775808"
# define MAX_LL "9223372036854775807"

typedef struct s_sig	t_sig;
extern int				g_exit_code;

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
	END,
	BADCHAR,
	D_BADCHAR
}						t_type;

typedef enum e_type_redir
{
	R_NONE,
	R_GREAT,
	RD_GREAT,
	R_LESS,
	RD_LESS,
}						t_type_redir;

typedef struct s_token
{
	char				*content;
	t_type				type;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_redir
{
	char				*file;
	int					fd;
	t_type_redir		type;
	struct s_redir		*next;
	struct s_redir		*prev;
}						t_redir;

typedef struct s_cmd
{
	int					argc;
	char				*cmd;
	char				**argv;
	char				*cmd_path;
	t_redir				*file;
	int					fd[2][2];
	pid_t				pid;
	t_token				*token;
	int					status;
	struct s_cmd		*next;
	struct s_cmd		*prev;
}						t_cmd;

typedef struct s_exp
{
	char				*var;
	int					index;
	struct s_exp		*next;
}						t_exp;

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_data
{
	t_token				*t;
	t_cmd				*cmd;
	t_env				*env;
	int					save_fd[2];
	char				**env_cpy;
	char				*line;
	bool				exit;
}						t_data;

// EXPAND
t_exp					*expnew(char *content, int index);
t_exp					*explast(t_exp *exp);
void					expclear(t_exp *exp);
void					expadd_back(t_exp **lst, t_exp *new);
char					*get_var(char *str, t_env *env);
int						get_var_len(char *str, t_env *env);
int						env_char(char c);
int						memory_needed(char *str, t_env *env, t_exp *exp);
t_exp					*init_expand(char *s);
char					*expand(char *s, t_env *env);
void					expand_func_3(char *s, int *i, int *in);

// STR
char					*remove_quotes(char *str);
int						skip_and_copy(char *str, char *ret, int *i, int *j);
void					skip_spaces(char *str, int *i, int *j);
char					*remove_spaces(char *s);
int						spaces_to_add(char *s);
int						space_func(char *s, char *ret, int *i, int *j);
char					*add_space(char *s);
char					*new_str(char *str, t_env *env);
int						is_space(char c);

// TOKEN
void					tokenadd_back(t_token **lst, t_token *new);
int						tokensize(t_token *lst);
t_token					*tokennew(char *content, t_type type);
void					tokenclear(t_token *lst);
t_token					*tokenlast(t_token *lst);
t_token					*tokenfirst(t_token *lst);
t_type					get_type(char *s);
t_token					*init_tokens(char *s);
void					give_types(t_token *t);
int						type_is_sep(t_type type);
void					quote(t_token *t);

// CMD
void					cmdadd_back(t_cmd **lst, t_cmd *new);
int						cmdsize(t_cmd *lst);
t_cmd					*cmdnew(char *content, t_token *token);
t_cmd					*cmdlast(t_cmd *lst);
t_cmd					*cmdfirst(t_cmd *lst);
char					*get_cmd_str(t_token *token);
t_token					*sub_token(t_token *token, int start, int size);
t_token					*create_token_cmd(t_token *token, int i);
void					arr_func(t_cmd *cmd, int *i, char **arr);
char					**char_arr(t_cmd *cmd);
t_cmd					*create_cmd(t_token *token, int i);
t_cmd					*create_all_cmd(t_token *t);
void					ft_append_redirection(t_cmd *cmd, t_redir *redir);
void					ft_assign_redirection_types(t_cmd *cmd);
t_redir					*ft_newredirection(char *file, t_type_redir type);
void					ft_redirect(t_token *t, t_cmd *cmd);

// PARSING
int						skip_quotes(char const *s, int *i);
int						closed_quotes(char *s);
int						max(int a, int b);
void					print_error(char *err);
int						parse_pipes(t_cmd *cmd);
int						parse_redirections(t_cmd *cmd);
int						token_is_redir(t_token *token);
int						err_redir(t_token *token);
int						parse(t_cmd *cmd);

// EXECUTE
void					execute(t_data *data);
int						exec(t_data *data, t_cmd *cmd);
int						execute_pipe(t_cmd *cmd, t_data *data);
void					exec_cmd(t_data *data, t_cmd *cmd);
int						ft_open(t_redir *file);
void					free_and_close(t_data *data);

// FD
void					ft_save_fd(t_data *data);
void					ft_restore_fd(t_data *data);
int						cmd_open(t_cmd *cmd);
void					ft_close_fd(t_cmd *cmd);
int						ft_create(char *file);
int						ft_append(char *file);
int						ft_read(char *file);
int						ft_heredoc(char *limiter);

// BUILTIN
bool					is_builtin(char *s);
int						builtin(t_cmd *cmd, t_data *data, int print);
int						cd(char **args, t_env *env);
int						echo(char **args);
int						env(t_env *env);
void					exit_builtin(char **args, t_data *data, int print);
int						export_builtin(char **args, t_data *data);
int						pwd(t_data *data);
int						unset(char **args, t_data *data);

// SIGNAL
void					sig_handler(int signum);
void					sigquit_handler(int sig);

// FREE
void					free_start(t_data *data);
void					free_end(t_data *data);
void					free_env(t_env *lst);
void					free_tab(void **tab);
void					free_cmd(t_cmd *lst);
void					ft_free(void **ptr);

// ENV
void					create_env_list(t_env **head, char **envp);
t_env					*env_new(char *en);
t_env					*envlast(t_env *head);
void					env_add_back(t_env **head, t_env *new_list);
char					*ft_getenv(t_env *env, char *key);
void					ft_setenv(t_env **env, char *key, char *value);
char					**env_to_tab(t_env *env);
int						ft_removeenv(t_env **env, char *key);

// UTILS
char					**ft_ssdup(char **ss);
char					*ft_strjoin2(char *s1, char *s2);
char					*getprompt(t_data *data);

#endif
