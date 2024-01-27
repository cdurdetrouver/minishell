/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 02:02:48 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/27 00:50:21 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief set the user in the prompt.
 *
 * @param data (t_data *) data
 * @param prompt (char *) prompt
 */
static void	pormpt_setuser(t_data *data, char *prompt)
{
	ft_strlcat(prompt, "\001\033[1;32m\002", 4096);
	if (ft_getenv(data->env, "USER"))
		ft_strlcat(prompt, ft_getenv(data->env, "USER"), 4096);
	else
		ft_strlcat(prompt, "guest", 4096);
	ft_strlcat(prompt, "\001\033[0m\002", 4096);
}

/**
 * @brief set the path in the prompt.
 *
 * @param data (t_data *) data
 * @param prompt (char *) prompt
 */
static void	pormpt_setpath(t_data *data, char *prompt)
{
	char	*cwd;

	ft_strlcat(prompt, "\001\033[1;34m\002", 4096);
	cwd = getcwd(NULL, 0);
	if (ft_getenv(data->env, "HOME") && cwd)
	{
		if (ft_strcmp(cwd, ft_getenv(data->env, "HOME")) == 0)
			ft_strlcat(prompt, "~", 4096);
		else
		{
			ft_strlcat(prompt, "../", 4096);
			ft_strlcat(prompt, ft_strrchr(cwd, '/') + 1, 4096);
		}
	}
	else
		ft_strlcat(prompt, "unknown", 4096);
	free(cwd);
	ft_strlcat(prompt, "\001\033[0m\002", 4096);
}

/**
 * @brief get the prompt.
 *
 * @return (char *) the prompt.
 */
char	*getprompt(t_data *data)
{
	static char	prompt[4096];

	ft_bzero(prompt, 4096);
	if (g_exit_code != 0)
		ft_strlcat(prompt, "💥 ", 4096);
	else
		ft_strlcat(prompt, "\001\xF0\x9F\002\x9F\xA2 ", 4096);
	pormpt_setuser(data, prompt);
	ft_strlcat(prompt, "@\001\033[1;33m\002minishell", 4096);
	ft_strlcat(prompt, "\001\033[0m\002: ", 4096);
	pormpt_setpath(data, prompt);
	ft_strlcat(prompt, "$ ", 4096);
	return (prompt);
}
