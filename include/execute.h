/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:13:26 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 16:51:20 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

int	builtin(char **args, t_data *data);
int					echo(char **args);
int					cd(char **args);
int					pwd(void);
int					export(char **args);
int					unset(char **args);
int					env(void);
int	exit_builtin(char **args, t_data *data);
void				sigint_handler(int signum);

#endif