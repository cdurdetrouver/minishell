/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 02:02:48 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/23 16:05:52 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief get the prompt.
 *
 * @return (char *) the prompt.
 */
char	*getprompt(void)
{
	char		*cwd;
	static char	prompt[4096];

	ft_bzero(prompt, 4096);
	if (g_sig.prompt_erreur == true)
		ft_strlcat(prompt, "💥 ", 4096);
	else
		ft_strlcat(prompt, "\001\xF0\x9F\002\x9F\xA2 ", 4096);
	ft_strlcat(prompt, "\001\033[1;32m\002", 4096);
	if (getenv("USER"))
		ft_strlcat(prompt, getenv("USER"), 4096);
	else
		ft_strlcat(prompt, "UNKNOW", 4096);
	ft_strlcat(prompt, "\001\033[0m\002@\001\033[1;33m\002", 4096);
	ft_strlcat(prompt, "minishell", 4096);
	ft_strlcat(prompt, "\001\033[0m\002: \001\033[1;34m\002", 4096);
	cwd = getcwd(NULL, 0);
	if (getenv("HOME"))
	{
		if (ft_strcmp(cwd, getenv("HOME")) == 0)
			ft_strlcat(prompt, "~", 4096);
		else
		{
			ft_strlcat(prompt, "../", 4096);
			ft_strlcat(prompt, ft_strrchr(cwd, '/') + 1, 4096);
		}
	}
	else
		ft_strlcat(prompt, "UNKNOW", 4096);
	free(cwd);
	ft_strlcat(prompt, "\001\033[0m\002$ ", 4096);
	return (prompt);
}
