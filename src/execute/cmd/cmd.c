/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:17:26 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/08 20:52:02 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * print the args given.
 *
 * @param args (char **) args
 * @return int 0 if it works, 1 if don't.
 */
int	echo(char **args)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		n = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!n)
		ft_putstr_fd("\n", 1);
	return (0);
}

/**
 * use cd on the path given.
 *
 * @param (char **) args
 * @return int 0 if it works, 1 if don't.
 */
int	cd(char **args)
{
	char	*path;

	if (args[1] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 1);
			return (1);
		}
	}
	else
		path = args[1];
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 1);
		ft_putstr_fd(path, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		return (1);
	}
	return (0);
}

/**
 * get the actual path
 *
 * @return int 0 if it works, 1 if don't.
 */
int	pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
	return (0);
}
/**
 *
 */
int	export(char **args)
{
	int	i;

	i = 1;
	if (args[1] == NULL)
		printf("env\n");
	else
	{
		while (args[i])
		{
			if (ft_strchr(args[i], '='))
				printf("add to env %s", args[i]);
			else
				ft_putstr_fd("minishell: export: `", 1);
			ft_putstr_fd(args[i], 1);
			ft_putstr_fd("': not a valid identifier\n", 1);
			i++;
		}
	}
	return (0);
}

int	unset(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
			ft_putstr_fd("minishell: unset: `", 1);
		ft_putstr_fd(args[i], 1);
		ft_putstr_fd("': not a valid identifier\n", 1);
		i++;
	}
	return (0);
}

int	env(void)
{
	printf("PATH=%s\n", getenv("PATH"));
	return (0);
}

int	exit_builtin(char **args)
{
	int	i;

	i = 1;
	if (args[1] == NULL)
		exit(1);
	else if (args[1] && args[2] == NULL)
	{
		while (args[1][i])
		{
			if (!ft_isdigit(args[1][i]))
			{
				ft_putstr_fd("minishell: exit: ", 1);
				ft_putstr_fd(args[1], 1);
				ft_putstr_fd(": numeric argument required\n", 1);
				exit(255);
			}
			i++;
		}
		exit(ft_atoi(args[1]));
	}
	else
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 1);
		return (1);
	}
	return (0);
}
