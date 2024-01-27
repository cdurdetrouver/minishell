/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:19:20 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/28 00:24:26 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_pwd(t_env *env, char *old_pwd)
{
	char	*cwd;
	char	buff[4097];

	if (!old_pwd)
		ft_setenv(&env, "OLDPWD", ft_getenv(env, "PWD"));
	else
		ft_setenv(&env, "OLDPWD", old_pwd);
	cwd = getcwd(buff, 4096);
	ft_setenv(&env, "PWD", cwd);
}

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
	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		if (print_path)
			printf("%s\n", path);
		set_pwd(env, cwd);
		g_exit_code = 0;
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		if (access(path, F_OK) == -1)
			ft_putendl_fd(": No such file or directory", 2);
		else if (access(path, R_OK) == -1)
			ft_putendl_fd(": Permission denied", 2);
		else
			ft_putendl_fd(": Not a directory", 2);
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
		if (ft_strcmp(args[1], "--") == 0 || ft_strcmp(args[1], "~") == 0)
			change_dir(ft_getenv(env, "HOME"), 0, env);
		else if (args[1][0] == '-' && !args[1][1])
			change_dir(ft_getenv(env, "OLDPWD"), 1, env);
		else
			change_dir(args[1], 0, env);
	}
	return (0);
}
