/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:22:29 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:44:09 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief join two strings.
 *
 * @param s1 (char *) string 1
 * @param s2 (char *) string 2
 * @return (char *) don't forget to free it.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[j] = s1[j];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		new[j] = s2[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}
