/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:35:19 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 22:15:02 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
