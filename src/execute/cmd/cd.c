/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:19:20 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 16:08:25 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_dir(char *path, int print_path, t_env *env)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		if (print_path)
			printf("%s\n", path);
		ft_setenv(env, "OLDPWD", cwd);
		g_sig.exit_code = 1;
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		if (access(path, F_OK) == -1)
			ft_putstr_fd("no such file or directory: ", 2);
		else if (access(path, R_OK) == -1)
			ft_putstr_fd("permission denied: ", 2);
		else
			ft_putstr_fd("not a directory: ", 2);
		ft_putendl_fd(path, 2);
		g_sig.prompt_erreur = true;
		g_sig.exit_code = 1;
	}
}

/**
 * use cd on the path given.
 *
 * @param (char **) args
 * @param (int) argc
 */
int	cd(char **args, t_env *env)
{
	if (!args[1])
	{
		change_dir(ft_getenv(env, "HOME"), 0, env);
		return (1);
	}
	if (args[2])
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		g_sig.prompt_erreur = true;
		g_sig.exit_code = 1;
		return (1);
	}
	else
	{
		if (ft_strcmp(args[1], "--") == 0)
			change_dir(ft_getenv(env, "HOME"), 0, env);
		else if (args[1][0] == '-' && !args[1][1])
			change_dir(ft_getenv(env, "OLDPWD"), 1, env);
		else
			change_dir(args[1], 0, env);
	}
	return (0);
}
