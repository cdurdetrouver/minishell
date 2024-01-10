/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:12:56 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 05:19:38 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*joinss(char **ss)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_strdup("");
	while (ss[i])
	{
		line = ft_strjoin2(line, ss[i]);
		i++;
	}
	return (line);
}

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
	free_tab(ss);
	return (s);
}

static char	*getprompt(void)
{
	char	*line;
	char	**prompt;
	char	hostname[1024];

	gethostname(hostname, 1024);
	prompt = malloc(sizeof(char *) * 7);
	if (!prompt)
		return (NULL);
	prompt[0] = ft_strdup("\001\033[1;32m\002");
	prompt[1] = getenv("USER");
	prompt[2] = ft_strdup("\001\033[0m\002@\001\033[1;33m");
	prompt[3] = ft_strdup("\002minishell\001\033[0m\002: \001\033[1;34m\002…/");
	prompt[4] = lastdir();
	prompt[5] = ft_strdup("\001\033[0m\002$ ");
	prompt[6] = NULL;
	line = joinss(prompt);
	free(prompt[0]);
	free(prompt[2]);
	free(prompt[3]);
	free(prompt[4]);
	free(prompt[5]);
	free(prompt);
	return (line);
}

void	minishell(t_data *data)
{
	char	*prompt;
	char	*replacement;

	data->start = NULL;
	using_history();
	while (data->exit == false)
	{
		prompt = getprompt();
		data->line = readline(prompt);
		add_history(data->line);
		replacement = "This is the replacement text";
		rl_replace_line(replacement, 0);
		rl_redisplay();
		parse(data);
		if (data->exec == true)
			execute(data);
		free(prompt);
		free(data->line);
		free_start(data->start);
	}
}
