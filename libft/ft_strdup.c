/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:04:42 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:45:14 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief copy a string with malloc.
 *
 * @param s (char *) string to copy
 * @return (char *) don't forget to free it.
 */
char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*s2;
	size_t	len;
	size_t	i;

	s2 = (char *)s;
	len = ft_strlen(s);
	dest = malloc(len * sizeof(char) + 1);
	i = 0;
	while (i < len)
	{
		dest[i] = s2[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
