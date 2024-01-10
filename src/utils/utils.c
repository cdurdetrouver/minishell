/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:23:34 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/10 04:58:50 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*ft_lstnew_env(char *str)
{
	t_env	*new;
	char	**ss;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	ss = ft_split(str, '=');
	if (!ss)
		return (NULL);
	if (!ss[0])
		new->key = ft_strdup("");
	else
		new->key = ft_strdup(ss[0]);
	if (!ss[1])
		new->value = ft_strdup("");
	else
		new->value = ft_strdup(ss[1]);
	free_tab(ss);
	new->next = NULL;
	return (new);
}

static void	ft_lstadd_back_env(t_env *head, t_env *new)
{
	t_env	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_env	*ft_lstenv(char **envp)
{
	t_env	*head;
	int		i;

	head = ft_lstnew_env(envp[0]);
	i = 1;
	while (envp[i])
	{
		ft_lstadd_back_env(head, ft_lstnew_env(envp[i]));
		i++;
	}
	return (head);
}

void	print_env(t_env *head)
{
	while (head)
	{
		ft_putstr_fd(head->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(head->value, 1);
		ft_putstr_fd("\n", 1);
		head = head->next;
	}
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	free(s1);
	return (str);
}
