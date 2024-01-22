/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:47:53 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 00:12:55 by gbazart          ###   ########.fr       */
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

typedef struct s_sig	t_sig;
extern t_sig			g_sig;

struct					s_sig
{
	int					exit_code;
	bool				prompt_erreur;
};

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
	SEMICOLON,
	ESPER,
	BSLASH
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
}						t_redir;

typedef struct s_cmd
{
	int					argc;
	char				*cmd;
	char				**argv;
	char				*cmd_path;
	t_redir				file_in;
	t_redir				file_out;
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

// MAIN
void					minishell(t_data *data);
bool					is_builtin(char *s);

// EXPAND
t_exp					*expnew(char *content, int index);
t_exp					*explast(t_exp *exp);
void					expclear(t_exp *exp);
void					expadd_back(t_exp **lst, t_exp *new);
int						get_var_len(char *str);
int						env_char(char c);
int						memory_needed(char *str, t_exp *exp);
t_exp					*init_expand(char *s);
void					print_expand(t_exp *exp);
char					*expand(char *s);
void					expand_func_3(char *s, int *i);

// STR
char					*remove_quotes(char *str);
int						skip_and_copy(char *str, char *ret, int *i, int *j);
void					skip_spaces(char *str, int *i, int *j);
char					*remove_spaces(char *s);
int						spaces_to_add(char *s);
int						space_func(char *s, char *ret, int *i, int *j);
char					*add_space(char *s);
char					*new_str(char *str);
int						is_space(char c);

// TOKEN
void					tokenadd_back(t_token **lst, t_token *new);
int						tokensize(t_token *lst);
t_token					*tokennew(char *content, t_type type);
void					tokenclear(t_token *lst);
t_token					*tokenlast(t_token *lst);
t_token					*tokenfirst(t_token *lst);
void					print_token(t_token *token);
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
void					print_cmd(t_cmd *cmd);
t_token					*create_token_cmd(t_token *token, int i);
void					arr_func(t_cmd *cmd, int *i, char **arr);
char					**char_arr(t_cmd *cmd);
t_cmd					*create_cmd(t_token *token, int i);
t_cmd					*create_all_cmd(t_token *t);
void	print_cmd_argv(t_cmd *cmd); // a supprimer
void					ft_assign_redirection_types(t_cmd *cmd);

// PARSING
int						skip_quotes(char const *s, int *i);
int						is_cmd(char *cmd);
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
void					exec_one(t_cmd *cmd, t_data *data);
void					ft_save_fd(t_cmd *cmd, t_data *data);
void					ft_restore_fd(t_data *data);
int						exec(t_data *data, t_cmd *cmd);
int						execute_pipe(t_cmd *cmd, t_data *data);
void					exec_cmd(t_data *data, t_cmd *cmd);
int						ft_open(t_cmd *cmd, t_redir *file);

// BUILTIN
bool					is_builtin(char *s);
int						builtin(t_cmd *cmd, t_data *data);
int						cd(char **args, t_env *env);
int						echo(char **args);
int						env(t_env *env);
void					exit_builtin(char **args, t_data *data);
int						export_builtin(char **args, t_env *env);
int						pwd(void);
int						unset(char **args, t_env *env);

// SIGNAL
void					sig_handler(int signum);

// FREE
void					free_start(t_data *data);
void					free_end(t_data *data);
void					free_tab(void **tab);
void					free_cmd(t_cmd *lst);
void					ft_free(void **ptr);
t_env					*create_env_list(char **envp);

// UTILS
char					**ft_ssdup(char **ss);
char					*ft_strjoin2(char *s1, char *s2);
char					*getprompt(void);
char					*ft_getenv(t_env *env, char *key);
void					ft_setenv(t_env *env, char *key, char *value);
char					**env_to_tab(t_env *env);
int						ft_removeenv(t_env **env, char *key);

// DEBUG
void					print_tab(char **tab);

#endif
