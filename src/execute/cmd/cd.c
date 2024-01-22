/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:19:20 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/22 12:41:58 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_dir(char *path, int print_path)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		if (print_path)
			printf("%s\n", path);
		setenv("OLDPWD", cwd, 0);
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
	}
}

/**
 * use cd on the path given.
 *
 * @param (char **) args
 * @param (int) argc
 */
int	cd(char **args)
{
	if (!args[1])
	{
		change_dir(getenv("HOME"), 0);
		return (1);
	}
	if (args[2])
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		g_sig.prompt_erreur = true;
		return (1);
	}
	else
	{
		if (ft_strcmp(args[1], "--") == 0)
			change_dir(getenv("HOME"), 0);
		else if (args[1][0] == '-' && !args[1][1])
			change_dir(getenv("OLDPWD"), 1);
		else
			change_dir(args[1], 0);
	}
	return (0);
}
