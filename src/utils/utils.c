/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:23:34 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/26 00:37:38 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief do the same as joiun but free the first string.
 *
 * @param s1 (char *) string to join and free.
 * @param s2 (char *) string to join.
 * @return (char *) don't forget to free it.
 */
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

/**
 * @brief duplicate a string array.
 *
 * @param ss (char **) string array to duplicate.
 * @return (char **) don't forget to free it.
 */
char	**ft_ssdup(char **ss)
{
	char	**new;
	int		i;

	i = 0;
	while (ss[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (ss[i])
	{
		new[i] = ft_strdup(ss[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
