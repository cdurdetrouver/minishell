/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:53:05 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:46:19 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief find a char in a string.
 *
 * @param s (char *) string
 * @param c (int) char to find
 * @return (char *) pointer to the char equal in the string or NULL.
 */
char	*ft_strchr(const char *s, int c)
{
	char	*ch;
	char	*copy;

	copy = (char *)s;
	if (c == 0)
		return (copy + ft_strlen(copy));
	ch = NULL;
	while (*copy)
	{
		if (*copy == (char)c)
		{
			ch = copy;
			return (ch);
		}
		copy++;
	}
	return (ch);
}
