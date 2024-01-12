/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 02:02:48 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/12 14:45:58 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief get the last dir of the path.
 *
 * @return (char *) the last dir of the path don't forget to free it.
 */
static char	*lastdir(void)
{
	char	**ss;
	char	*s;
	char	*tmp;
	int		i;

	i = 0;
	tmp = getcwd(NULL, 0);
	if (!tmp)
		return (NULL);
	ss = ft_split(tmp, '/');
	if (!ss)
		return (NULL);
	free(tmp);
	while (ss[i])
		i++;
	if (i == 0)
		s = ft_strdup("/");
	else
		s = ft_strdup(ss[i - 1]);
	free_tab((void **)ss);
	return (s);
}

/**
 * @brief get the prompt.
 *
 * @return (char *) the prompt don't forget to free it.
 */
char	*getprompt(void)
{
	char	*line;
	char	*tmp;
	char	prompt[128][6];

	if (g_sig.code_prompt)
		line = ft_strdup("💥 ");
	else
		line = ft_strdup("\001\xF0\x9F\002\x9F\xA2 ");
	ft_strlcpy(prompt[0], "\001\033[1;32m\002", 18);
	line = ft_strjoin2(line, prompt[0]);
	tmp = getenv("USER");
	ft_strlcpy(prompt[1], tmp, ft_strlen(tmp) + 1);
	line = ft_strjoin2(line, prompt[1]);
	ft_strlcpy(prompt[2], "\001\033[0m\002@\001\033[1;33m", 128);
	line = ft_strjoin2(line, prompt[2]);
	ft_strlcpy(prompt[3],
		"\002minishell\001\033[0m\002: \001\033[1;34m\002.../", 52);
	line = ft_strjoin2(line, prompt[3]);
	tmp = lastdir();
	ft_strlcpy(prompt[4], tmp, ft_strlen(tmp) + 1);
	line = ft_strjoin2(line, prompt[4]);
	free(tmp);
	ft_strlcpy(prompt[5], "\001\033[0m\002$ ", 17);
	line = ft_strjoin2(line, prompt[5]);
	return (line);
}
