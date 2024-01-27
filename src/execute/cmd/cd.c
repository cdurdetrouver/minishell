/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:19:20 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 00:34:46 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * change the current directory to the path given.
 *
 * @param (char *) path
 * @param (int) print_path
 */
static void	change_dir(char *path, int print_path, t_env *env)
{
	char	*cwd;
	char	buff[4097];

	if (!path)
		return ;
	if (!chdir(path))
	{
		cwd = getcwd(buff, 4096);
		if (print_path)
			printf("%s\n", path);
		ft_setenv(&env, "OLDPWD", cwd);
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
		g_exit_code = 1;
	}
}

/**
 * change the current directory to the path given.
 *
 * @param (char **) args
 * @param (t_env *) env
 * @return (int) 1
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
		g_exit_code = 1;
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
